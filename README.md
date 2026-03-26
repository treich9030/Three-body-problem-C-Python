# Three-body-problem-C-Python
This combination of C and Python code simulates a basic gravitational three-body system, defined by its stochastic nature. This project is meant to display proficiency in scientific computing in C, visual computing/plotting in Python using Plotly, and an understanding of numerical integration methods and physics-based differential calculus.  

Compatibility with C (including a compiler), and Python -- with the Plotly library installed -- is required. While contextualized to VSCode, this link [here]([https://code.visualstudio.com/docs/languages/cpp]) has several C compilers linked for download, for Windows, Max, and Linux. 

This simulation includes several presets for the initial positions and velocities of the three bodies, including classical solutions, modern stable solutions, and modern unstable solutions to the three-body problem. Note about the modern unstable solutions: they are unstable over longer simulations, which means that the default dt, frame_skip, and duration values in the program(s) may not work well. Consider adjusting if you wish to run these presets. The initial parameters for the modern unstable solutions used come from the Institute of Physics at Belgrade, specifically [here]([url](http://three-body.ipb.ac.rs/)). 

To adjust the custom preset, use the given file 'custominput.txt'. The format for the file is
              mass x_coordinate y_coordinate velocity_x velocity_y,
where there are three rows, one for each orbital body. An example is given in custominput.txt.

In a terminal window, simply running 'run.bat' will execute the C program (threebody.c), the Python program (animate.py), and open the resultant HTML animation (simulation.html) into a default browser window. There, you can adjust the zoom, framerate, and progression along the simulation with the slider below the plot. 
