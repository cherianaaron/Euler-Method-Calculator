#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

/** This is a program that implements Euler's Method as part
*   Chapter 2.4: Numerical Approximation.

MATH 3280: Differential Equations and Linear Algebra.

Equation:

dy/dx = y*e^(-x^2)

@author Aaron Cherian
@date Friday Feb 7th, 2020
*/

float diffEquation(float x, float y)
{
    return y*(pow(exp(1), pow(-x,2))); // ye^(-x^2)
}

int main ()
{
    float xInitial = 0;
    float yInitial = 1;
    float h1 = 0.001;
    float h2 = 0.0001;
    float x = 0; //starting interval
    float y = 1; //ending interval
    float temp;
    ofstream myfile;
    myfile.open ("example.xls");
    myfile << "\n x-values\t  y-values\n";
    while(xInitial < y){
        temp = h1*diffEquation(xInitial,yInitial);
        yInitial = yInitial + temp;
        xInitial = xInitial + h1;
        //temp = y;
        //y = y + h1*diffEquation(xInitial,y);
        //xInitial = xInitial + h1;

        myfile << xInitial <<  "\t" << yInitial << endl;
    }
    myfile.close();

}

