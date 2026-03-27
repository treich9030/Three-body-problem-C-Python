#include <stdio.h>
#include <math.h>

/*Function prototypes*/
void menu_open(int *option);
void preset_lagrange(double *bodies, double *masses);
void preset_euler(double *bodies, double *masses);
void preset_figure8(double *bodies, double *masses);
void preset_broucke(double *bodies, double *masses);
void preset_henon(double *bodies, double *masses);
void preset_yarn(double *bodies, double *masses);
void preset_yinyang(double *bodies, double *masses);
void preset_dragonfly(double *bodies, double *masses);
void preset_sheen(double *bodies, double *masses);
void preset_custom(double *bodies, double *masses);
void derivative(double *bodies, double *masses, double *deriv_bodies);
void rk4_integration(double *bodies, double *masses, double dt);
void simulate(double *bodies, double *masses);

/*Where the magic happens*/
int main() 
{   
    double bodies[12]; /*Body data -- x, y, x velocity, y velocity of the three bodies*/
    double masses[3]; /*Masses of the three bodies*/
    int option;

    menu_open(&option);

    switch (option) {
        case 1: 
            preset_lagrange(bodies, masses);
            break;
        case 2: 
            preset_euler(bodies, masses);
            break;
        case 3: 
            preset_figure8(bodies, masses);
            break;
        case 4:
            preset_broucke(bodies, masses);
            break;
        case 5:
            preset_henon(bodies, masses);
            break;
        case 6:
            preset_yarn(bodies, masses);
            break;
        case 7:
            preset_yinyang(bodies, masses);
            break;
        case 8:
            preset_dragonfly(bodies, masses);
            break;
        case 9:
            preset_sheen(bodies, masses);
            break;
        case 10:
            preset_custom(bodies, masses);
            break;
        default:
            printf("Invalid option selected. Exiting program.\n");
            return -1;
    }

    simulate(bodies, masses);

    printf("Simulation complete. Data saved to data.csv\n");

    return 0;

}

/*Prompts a TUI for the user to select from*/
void menu_open(int *option)
{
    printf("\nWelcome to my graviational three body simulator!\n");
    printf("Please select a stable solution to simulate, or simualte a custom configuration\n\n");
    printf("Classical Solutions:\n[1] Lagrange's Triangle\t[2] Euler's Collinear\n");
    printf("Modern Stable Solutions:\n[3] Figure-8\t\t[4] Broucke\n[5] Henon\n");
    printf("Modern Unstable Solutions (see README):\n");
    printf("[6] Yarn\t\t[7] Yin-Yang 1a\n[8] Dragonfly\t\t[9] Sheen I\n");
    printf("[10] Custom Configuration -- see README for details\n");
    printf("Enter here --> ");

    scanf("%d", &*option);
}

/*Loads preset configurations*/
void preset_lagrange(double *bodies, double *masses)
{
    masses[0] = 1.0;
    bodies[0] = 3.0;
    bodies[1] = 0.0;
    bodies[2] = 0.0;
    bodies[3] = 0.5;

    masses[1] = 1.0;
    bodies[4] = -1.5;
    bodies[5] = 2.59807621;
    bodies[6] = -0.43301275;
    bodies[7] = -0.25;

    masses[2] = 1.0;
    bodies[8] = -1.5;
    bodies[9] = -2.59807621;
    bodies[10] = 0.4330127;
    bodies[11] = -0.25;
}

void preset_euler(double *bodies, double *masses)
{
    masses[0] = 1.0;
    bodies[0] = -1.0;
    bodies[1] = 0.0;
    bodies[2] = 0.0;
    bodies[3] = -0.5;

    masses[1] = 1.0;
    bodies[4] = 0.0;
    bodies[5] = 0.0;
    bodies[6] = 0.0;
    bodies[7] = 1.0;

    masses[2] = 1.0;
    bodies[8] = 1.0;
    bodies[9] = 0.0;
    bodies[10] = 0.0;
    bodies[11] = -0.5;
}

void preset_figure8(double *bodies, double *masses)
{
    masses[0] = 1.0;
    bodies[0] = 0.97000436;
    bodies[1] = -0.24308753;
    bodies[2] = 0.4662036850;
    bodies[3] = 0.4323657300;

    masses[1] = 1.0;
    bodies[4] = -0.97000436;
    bodies[5] = 0.24308753;
    bodies[6] = 0.4662036850;
    bodies[7] = 0.4323657300;

    masses[2] = 1.0;
    bodies[8] = 0.0;
    bodies[9] = 0.0; 
    bodies[10] = -0.93240737;
    bodies[11] = -0.86473146;
}

void preset_broucke(double *bodies, double *masses)
{
    masses[0] = 1.0;
    bodies[0] = 0.013260484;
    bodies[1] = 0.0;
    bodies[2] = 0.0;
    bodies[3] = 1.054151921;

    masses[1] = 1.0;
    bodies[4] = 1.4157286016;
    bodies[5] = 0.0;
    bodies[6] = 0.0;
    bodies[7] = -0.2101466639;

    masses[2] = 1.0;
    bodies[8] = -1.4289890859;
    bodies[9] = 0.0; 
    bodies[10] = 0.0;
    bodies[11] = -0.8440052572;
}

void preset_henon(double *bodies, double *masses)
{
    masses[0] = 1.0;
    bodies[0] = 0.4752073013;
    bodies[1] = 0.0;
    bodies[2] = 0.0;
    bodies[3] = 1.1801113507;

    masses[1] = 1.0;
    bodies[4] = 1.2395152885;
    bodies[5] = 0.0;
    bodies[6] = 0.0;
    bodies[7] = -0.4523369153;

    masses[2] = 1.0;
    bodies[8] = -1.7147225898;
    bodies[9] = 0.0; 
    bodies[10] = 0.0;
    bodies[11] = -0.7277744354;
}

void preset_yarn(double *bodies, double *masses)
{
    masses[0] = 1.0;
    bodies[0] = -1.0;
    bodies[1] = 0.0;
    bodies[2] = 0.464445;
    bodies[3] = 0.396060;

    masses[1] = 1.0;
    bodies[4] = 1.0;
    bodies[5] = 0.0;
    bodies[6] = 0.464445;
    bodies[7] = 0.396060;

    masses[2] = 1.0;
    bodies[8] = 0.0;
    bodies[9] = 0.0; 
    bodies[10] = -2 * 0.464445;
    bodies[11] = -2 * 0.396060;
}

void preset_yinyang(double *bodies, double *masses)
{
    masses[0] = 1.0;
    bodies[0] = -1.0;
    bodies[1] = 0.0;
    bodies[2] = 0.513938;
    bodies[3] = 0.304736;

    masses[1] = 1.0;
    bodies[4] = 1.0;
    bodies[5] = 0.0;
    bodies[6] = 0.513938;
    bodies[7] = 0.304736;

    masses[2] = 1.0;
    bodies[8] = 0.0;
    bodies[9] = 0.0; 
    bodies[10] = -2 * 0.513938;
    bodies[11] = -2 * 0.304736;
}

void preset_dragonfly(double *bodies, double *masses)
{
    masses[0] = 1.0;
    bodies[0] = -1.0;
    bodies[1] = 0.0;
    bodies[2] = 0.080584;
    bodies[3] = 0.588836;

    masses[1] = 1.0;
    bodies[4] = 1.0;
    bodies[5] = 0.0;
    bodies[6] = 0.080584;
    bodies[7] = 0.588836;

    masses[2] = 1.0;
    bodies[8] = 0.0;
    bodies[9] = 0.0; 
    bodies[10] = -2 * 0.080584;
    bodies[11] = -2 * 0.588836;
}

void preset_sheen(double *bodies, double *masses)
{
    masses[0] = 1.0;
    bodies[0] = 0.716248295713;
    bodies[1] = 0.384288553041;
    bodies[2] = 1.245268230896;
    bodies[3] = 2.444311951777;

    masses[1] = 1.0;
    bodies[4] = 0.086172594591;
    bodies[5] = 1.342795868577;
    bodies[6] = -0.675224323690;
    bodies[7] = -0.962879613630;

    masses[2] = 1.0;
    bodies[8] = 0.538777980808;
    bodies[9] = 0.481049882656; 
    bodies[10] = -0.570043907206;
    bodies[11] = -1.481432338147;
}

void preset_custom(double *bodies, double *masses)
{
    FILE *fptr_custom = fopen("custominput.txt", "r");
    if (fptr_custom == NULL) {
        printf("Error opening file! Exiting program.\n");
        return;
    }

    fscanf(fptr_custom, "%lf %lf %lf %lf %lf", 
        &masses[0], &bodies[0], &bodies[1], &bodies[2], &bodies[3]);
    fscanf(fptr_custom, "%lf %lf %lf %lf %lf", 
        &masses[1], &bodies[4], &bodies[5], &bodies[6], &bodies[7]);
    fscanf(fptr_custom, "%lf %lf %lf %lf %lf", 
        &masses[2], &bodies[8], &bodies[9], &bodies[10], &bodies[11]);

    fclose(fptr_custom);
}

/*Calculates derivatives of body data (velocities and accelerations)*/
void derivative(double *bodies, double *masses, double *deriv_bodies)
{
    int i, j;
    double acc_x, acc_y, curr_x, curr_y, r;

    for (i = 0; i < 3; i++) {
        curr_x = bodies[i * 4];
        curr_y = bodies[i * 4 + 1];
        acc_x = 0.0;
        acc_y = 0.0;

        for (j = 0; j < 3; j++) {
            if (i != j) {
                r = sqrt(pow(bodies[j * 4] - curr_x, 2) + 
                    pow(bodies[j * 4 + 1] - curr_y, 2) + .20); /*+.20 is a pad; prevents near-zero division*/
                acc_x += masses[j] * (bodies[j * 4] - curr_x) / pow(r, 3);
                acc_y += masses[j] * (bodies[j * 4 + 1] - curr_y) / pow(r, 3);
            }
        }
        deriv_bodies[i * 4] = bodies[i * 4 + 2]; /*vel_x*/
        deriv_bodies[i * 4 + 1] = bodies[i * 4 + 3]; /*vel_y*/
        deriv_bodies[i * 4 + 2] = acc_x; /*acc_x*/
        deriv_bodies[i * 4 + 3] = acc_y; /*acc_y*/
    }
}

/*RK4 Integration; takes four derivities along one time step*/
void rk4_integration(double *bodies, double *masses, double dt)
{
    double k1[12], k2[12], k3[12], k4[12], temp[12];

    derivative(bodies, masses, k1);

    for (int i = 0; i < 12; i++) 
        temp[i] = bodies[i] + 0.5 * dt * k1[i];
    derivative(temp, masses, k2);

    for (int i = 0; i < 12; i++) 
        temp[i] = bodies[i] + 0.5 * dt * k2[i];
    derivative(temp, masses, k3);

    for (int i = 0; i < 12; i++) 
        temp[i] = bodies[i] + dt * k3[i];
    derivative(temp, masses, k4);

    for (int i = 0; i < 12; i++) 
        bodies[i] += (dt / 6.0) * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
}

/*Calculates and pastes data into data.csv using RK4 integration*/
void simulate(double *bodies, double *masses)
{
    double dt = 1e-2; /*Time step*/
    double time_tot = 0.0;
    FILE *fptr = fopen("data.csv", "w");
    if (fptr == NULL) {
        printf("Error opening file! Exiting program.\n");
        return;
    }

    while (time_tot < 100.0) {  
        fprintf(fptr, "%lf,%lf,%lf,%lf,%lf,%lf\n", 
            bodies[0], bodies[1], bodies[4], bodies[5], bodies[8], bodies[9]);

        rk4_integration(bodies, masses, dt);

        /*Time Increment*/
        time_tot += dt;
    }
    fclose(fptr);
}