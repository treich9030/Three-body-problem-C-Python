# The Three-Body Problem in C and Python
## Introduction

This combination of C and Python code simulates a basic gravitational three-body system, defined by its stochastic nature. This project is meant to display proficiency in scientific computing in C, visual computing/plotting in Python using Plotly, and an understanding of numerical integration methods and physics-based differential calculus.  

Compatibility with C (including a compiler), and Python -- with the Plotly library installed -- is required. While contextualized to VSCode, this link [here](https://code.visualstudio.com/docs/languages/cpp) has several C compilers linked for download, for Windows, Max, and Linux. 

In a terminal window, simply running 'run.bat' will execute the C program (threebody.c), the Python program (animate.py), and open the resultant HTML animation (simulation.html) into a default browser window. There, you can adjust the zoom, framerate, and progression along the simulation with the slider below the plot.

## Benchmark Analysis
While the majority of interative-based numerical analyses of situations such as a three-body orbital system use either a mix or of excusively Python, Java, etc., this simulation conducts its interation in C. Since C is a compiler-based language and runs directly on the CPU, it is much faster than interpreted languages such as Python. Thus, this simulation is especially powerful for rapid simulations of small-scale three-body problems. This could be used as a teaching tool, an easy, fast way to test certain inital conditions, etc.

## Presets

This simulation includes several presets for the initial positions and velocities of the three bodies, including classical solutions, modern stable solutions, and modern unstable solutions to the three-body problem. An example simulation of perhaps the most famous stable solution to the three-body problem, the Lagrange equilateral triangle, is displayed below.

![Custom GIF](https://raw.githubusercontent.com/treich9030/Three-body-problem-C-Python/main/demo/Lagrange.gif)

Note about the modern unstable solutions: they are unstable over longer simulations, which means that the default dt, frame_skip, and duration values in the program(s) may not work well. Consider adjusting if you wish to run these presets. The initial parameters for the modern unstable solutions used come from the Institute of Physics at Belgrade, specifically [here](http://three-body.ipb.ac.rs/). 

To adjust the custom preset, use the given file 'custominput.txt'. The format for the file is

```
mass x_coordinate y_coordinate velocity_x velocity_y
```
where there are three rows, one for each orbital body. An example is given in custominput.txt, whose simulation is displayed below. 

![Custom GIF](https://raw.githubusercontent.com/treich9030/Three-body-problem-C-Python/main/demo/Custom.gif)

## Inteative Method -- RK4
The iterative method used here is known as RK4, from the Runge-Kutta family of iterative methods used in numerical analysis. RK4 takes four seperate derivitves of the sample data along one time step (k1 at t = 0, k2 & k3 at t = dt/2, k4 at t = dt) instead of one derivitve at the start of each time step. The inclusion of four slopes instead of one creates a much more accurate iteration, and can follow rapid fluctuation in sample data more easily than a simpley method such as Euler's.

Image courtesy of Low-Dimensional Energy Balance Models by Benjamin Schmiedel
