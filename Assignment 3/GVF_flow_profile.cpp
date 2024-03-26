#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// dy/dx = (S0 - Sf)/(1 - F^2)
//
// Sf = Q^2*n^2 / A^2*R^(2/3)
//
// Runge Kutta Method:
//    dy/dx = f(x)
//    K1 = h*f(x_n,y_n)
//    K2 = h*f( x_n+h , y_n+k1 )
//
//    y_(n+1) = y_n + (1/2)(k1+k2)

double f(double x, double y) {
  // Sf = Q^2*n^2*P^(4/3) / A^(10/3)
  double S0 = 0.001, Q = 10, n = 0.035, P = 40 + sqrt(5) * 2 * y,
         A = y * (2 * y + 40);
  double Sf = Q * Q * n * n * pow(P, 4 / 3) / (pow(A, 10 / 3));
  double Fr = Q / (A * sqrt(9.81 * y));

  return (S0 - Sf) / (1 - Fr * Fr);
}

int main(int argc, char *argv[]) {
  freopen("outputProfile.txt", "w", stdout);
  double dist = 18000;
  double nDivs = 18000;
  cout << nDivs << endl;
  double Q = 10;
  double h = dist / nDivs;
  vector<double> y(nDivs, 0), x(nDivs, 0), v(nDivs, 0);
  y[0] = 5.;
  for (int i = 0; i < nDivs; i++) {
    // depth[i] = (depth[i - 1] - (depth[i - 1] / 2.)) / (1. - nDivs / 2.);

    vector<double> k(2, 0);
    k[0] = h * f(x[i], y[i]);
    k[1] = h * f(x[i] + h, y[i] + k[0]);
    y[i + 1] = y[i] + (k[0] + k[1]) / 2;

    cout << y[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < nDivs; i++) {
    double A = y[i] * (2 * y[i] + 40);
    v[i] = Q / A;
    cout << v[i] << " ";
  }

  return 0;
}
