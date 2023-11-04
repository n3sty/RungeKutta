// RungeKutta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


// Sample differential equation (dy/dx = (x-y)/2)
float dydx(float x, float y) {
    return ((x-y) / 2);
}


// Finds value y for a given x using stepsize h and 
// initial value y0 at x0
float RungeKutta(float x0, float y0, float x, float h) {
    
    //Count number of iterations using stepsize h
    int n = (int)((x - x0) / h);

    float k1, k2, k3, k4, k5;

    //Iterate for number of iterations
    float y = y0;
    for (int i = 1; i <= n; i++) {
        
        // Apply Runge Kutta methods to find the next value of y
        k1 = dydx(x0, y);
        k2 = dydx(x0 + (h / 2), y + ((h * k1) / 2));
        k3 = dydx(x0 + (h / 2), y + ((h * k2) / 2));
        k4 = dydx(x0 + h, y + (h * k3));

        // Compute the next value of y
        y = y + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);

        // Update the next value of x
        x0 = x0 + h;
    }

    return y;
}


// Driver method
int main()
{
    float x0 = 0, y = 1, x = 2, h = 0.2;

    printf("\nThe value of y at x is: %f",
        RungeKutta(x0, y, x, h));
    
    return 0;
}

