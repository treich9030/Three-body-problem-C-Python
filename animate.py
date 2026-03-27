
import pandas as pd
import plotly.graph_objects as go


df = pd.read_csv("data.csv", header = None, names = ["x0", "y0", "x1", "y1", "x2", "y2"])

frame_skip = 20
trail_length = 300             
duration  = 33.3 # ms per frame  

colors = ["#6D1D31", "#1F306E", "#39B939"]
labels = ["1", "2", "3"]
bodies = [("x0","y0"), ("x1","y1"), ("x2","y2")]

# Filters data.csv for performance -- change the number within iloc to adjust
df = df.iloc[::frame_skip].reset_index(drop=True) 

# Create frames for animation
frames = []

for i in range(len(df)):
    trail_start = max(0, i - trail_length)
    past = df.iloc[trail_start : i+1]

    row  = df.iloc[i]

    frame_data = []

    for (xc, yc), color in zip(bodies, colors):
        frame_data.append(go.Scatter(
            x=past[xc], y=past[yc],
            mode="lines",
            line=dict(color=color, width=1.5),
            opacity=0.6,
            hoverinfo="skip"
        ))

    frame_data.append(go.Scatter(
        x=[row["x0"], row["x1"], row["x2"]],
        y=[row["y0"], row["y1"], row["y2"]],
        mode="markers+text",
        marker=dict(size=10, color=colors),
        text=labels,
        textposition="top center",
        textfont=dict(color="white", size=11),
        hoverinfo="text"
    ))

    frames.append(go.Frame(data=frame_data, name=str(i)))

fig = go.Figure(data=frames[0].data, frames=frames)

# Layout
all_x = pd.concat([df["x0"], df["x1"], df["x2"]])
all_y = pd.concat([df["y0"], df["y1"], df["y2"]])
pad   = (all_x.max() - all_x.min()) * 0.1   # 10% padding

fig.update_layout(
    title=dict(text="A Rudimentary Simulation of the Three Body Problem", 
               font=dict(color="white")),
    plot_bgcolor="black",
    paper_bgcolor="#2C3147",
    font=dict(color="white"),
    xaxis=dict(
        range=[all_x.min()-pad, all_x.max()+pad],
        scaleanchor="y",          # keeps aspect ratio square
        showgrid = False,
        zeroline = False,
        color = "white",
        showline = True,
        linecolor = "white",
        linewidth = 1.5,
        mirror = True 
    ),
    yaxis=dict(
        range=[all_y.min()-pad, all_y.max()+pad],
        showgrid=False,
        zeroline=False,
        color="white"
    ),
    showlegend=False,

    # Play & pause buttons
    updatemenus=[dict(
        type="buttons",
        showactive=False,
        y=1.05, x=1.0,
        buttons=[
            dict(
                label = "0.5x",
                method = "animate",
                args = [None, {
                    "frame": {"duration": 66.6, "redraw": True},
                    "fromcurrent": True,
                    "transition": {"duration": 0}
                }]
            ),
            dict(
                label="1x",
                method = "animate",
                args = [None, {
                    "frame": {"duration": 33.3, "redraw": True},
                    "fromcurrent": True,
                    "transition": {"duration": 0}
                }]
            ),
            dict(
                label = "2x",
                method = "animate",
                args=[None, {
                    "frame": {"duration": 16.6, "redraw": True},
                    "fromcurrent": True,
                    "transition": {"duration": 0}
                }]
            ),
            dict(
                label = "Pause",
                method = "animate",
                args = [[None], {
                    "frame": {"duration": 0},
                    "mode": "immediate",
                    "transition": {"duration": 0}
                }]
            )
        ]
    )],

    # Step slider
    sliders=[dict(
        currentvalue=dict(prefix="Step #: ", font=dict(color="white")),
        pad=dict(t=50),
        steps=[
            dict(
                method="animate",
                args=[[str(i)], {
                    "frame": {"duration": 0, "redraw": True},
                    "mode": "immediate"
                }],
                label=str(i)
            )
            for i in range(len(df))
        ]
    )]
)

# Export animation to HTML 
fig.write_html("simulation.html")
print("Done — open simulation.html in your browser")

