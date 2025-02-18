#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001  // Convergence criterion
#define MAX_ITER 100    // Maximum number of iterations

// Function representing the equation f(x) = x^2 + 48x - 324
double f(double x) {
    return x * x + 48 * x - 324;
}

// Derivative of the function f'(x) = 2x + 48
double df(double x) {
    return 2 * x + 48;
}

// Newton-Raphson method
void newtonRaphson(double initial_guess) {
    double x = initial_guess; // Initial guess
    int iter = 0;

    while (fabs(f(x)) > EPSILON && iter < MAX_ITER) {
        if (df(x) == 0) { // Avoid division by zero
            printf("Derivative is zero. Newton-Raphson method fails.\n");
            return;
        }

        x = x - f(x) / df(x); // Newton-Raphson formula
        iter++;
    }

    if (fabs(f(x)) <= EPSILON) {
        printf("The speed of the stream is: %.4f km/h\n", x);
    } else {
        printf("Solution did not converge.\n");
    }
}

int main() {
    double initial_guess = 5.0; // Initial guess for Newton-Raphson
    newtonRaphson(initial_guess);
    return 0;
}

}

