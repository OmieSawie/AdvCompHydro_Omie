#include <bits/stdc++.h>
#include <vector>
using namespace std;

// TDMA Function
vector<double> thomas_algorithm(std::vector<double> &a, std::vector<double> &b,
                                std::vector<double> &c,
                                std::vector<double> &d) {
  int n = d.size();

  std::vector<double> d_star(n, 0.);
  std::vector<double> c_star(n, 0.);

  d_star[0] = d[0];
  c_star[0] = c[0];

  for (int i = 1; i < n; i++) {
    d_star[i] = d[i] - (b[i] * a[i - 1] / d_star[i - 1]);
    c_star[i] = c[i] - (c_star[i - 1] * b[i] / d_star[i - 1]);
    /* cout << "d*" << d_star[i] << " "; */
  }

  vector<double> func(n, 0.);
  func[n - 1] = c_star[n - 1] / d_star[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    func[i] = (c_star[i] - (a[i] * func[i + 1])) / d_star[i];
    /* cout << func[i] << " "; */
  }
  return func;
}

/* Main()  function */
int main() {

  freopen("outputProfile.txt", "r",
          stdin); // Set input file as the output file generated by the
                  // GVF_flow_profile.cpp code.
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double E = 100, k = 0.0001; // As given in the question

  int nDivs = 0;
  cin >> nDivs;           // Take input of number of divisions
  double Length = 18000.; // Length of channel

  double delta_x = (double)(Length / nDivs);

  vector<double> b(nDivs + 1, 0.);
  vector<double> d(nDivs + 1, 0.);
  vector<double> a(nDivs + 1, 0.);
  vector<double> c(nDivs + 1, 0.);
  vector<double> V(nDivs + 1, 0.); // Velocities vector
  vector<double> y(nDivs + 1, 0.); // Flow depth vector

  for (int i = 0; i < nDivs; i++) {
    cin >> y[i]; // Take input of flow depths
  }
  for (int i = 0; i < nDivs; i++) {
    cin >> V[i];
    // Take input of Velocities; The Previous code file ie.
    // "GVF_flow_profile.cpp" outputs the depth data as well as
    // velocity data to "outputProfile.txt"
  }
  V[nDivs] = V[nDivs - 1];
  vector<double> Vinverted(nDivs + 1, 0.);
  for (int i = 0; i <= nDivs; i++) {
    Vinverted[i] = V[nDivs - i];
    // Invert the order of velocity data, as in the case of pollutant
    // concentration, we take the upstream point as the start point
  }

  // Initial condition of Source Pollution at 18KM upstream
  b[0] = 0;
  d[0] = -1;
  a[0] = 0;
  c[0] = -0.01 * 1000;

  // End Boundary Neumann Condition of Steady State dC/dx = 0;
  b[nDivs] = 0;
  d[nDivs] = -1;
  a[nDivs] = 1;
  c[nDivs] = 0;

  // Fill the A matrix (AX=B)
  for (int i = 1; i < nDivs; i++) {
    b[i] = (E / (delta_x * delta_x)) - (Vinverted[i] / (2 * delta_x));
    d[i] = -(2 * E / (delta_x * delta_x)) + (k);
    a[i] = (E / (delta_x * delta_x)) - (Vinverted[i] / (2 * delta_x));
    c[i] = 0;
  }

  // Middle condition of addition of pollutant source at 10KM upstream
  b[nDivs * 8 / 18] = 0;
  d[nDivs * 8 / 18] = -1;
  a[nDivs * 8 / 18] = 0;
  c[nDivs * 8 / 18] = -0.005 * 1000;

  // Run the data in the TDMA function defined above
  vector<double> answer = thomas_algorithm(a, b, c, d);

  // Set Output File
  freopen("outputConventration.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Output the number of divisions
  cout << nDivs + 1 << endl;

  // Output the concentration values
  for (int i = answer.size(); i >= 0; i--) {
    cout << answer[i] << " ";
  }
  cout << endl;

  // Output the values of x distance
  for (int i = 0; i < answer.size(); i++) {
    cout << -(double)((double)(i)*Length / (double)(nDivs)) << " ";
  }

  return 0;
}
