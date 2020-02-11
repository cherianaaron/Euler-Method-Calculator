#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

/** This is a program that implements Euler's Method as part
*   Chapter 2.4: Numerical Approximation.

MATH 3280: Differential Equations and Linear Algebra.

Equation:

dy/dx = y*e^(-x^2)

Algorithm:

y(n+1) = y(n) + (h * f(x(n), y(n)))

@author Aaron Cherian
@date Friday Feb 7th, 2020
*/

float diffEquation(float x, float y)
{
    return y*(pow(exp(1), pow(-x,2))); // ye^(-x^2)
}

int main ()
{
    /*Initial values*/
    float xInitial = 0; //initial x value
    float yInitial = 1; //initial y value
    float h1 = 0.001; //step size 1
    float h2 = 0.0001; //step size 2
    float endX = 1; //ending interval
    float temp; //dummy variable to store f(x,y)*h

    ofstream myfile;
    myfile.open ("Euler_Data.xls"); //opens a file to add graph data in
    myfile << "\n x-values\t  y-values\n"; //axis labels

    float newX = xInitial;
    float newY = yInitial;

    while(newX <= endX){ //while X is in interval [0,1]
        temp = h1*diffEquation(newX,newY); //temp = f(x,y)*h
        newY = newY + temp; //y1 = y0 + temp
        newX = newX + h1; //x1 = x0 + h

        //After above lines x0 = x1, and y0 = y1. Then the values
        //printed below to a file. This step is looped till end of
        //interval.

        myfile << newX <<  "\t" << newY << endl; //(x1,y1)....(x2,y2)...(xn,yn)
    }
    cout << "Your data has been outputted to Euler-Data.xls" << endl;
    myfile.close(); //closes and saves data

}

