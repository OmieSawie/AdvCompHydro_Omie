#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstddef>
#include <vector>
using namespace std;

/* clang-format off */

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


/* DEBUGGER printer */
void _print(int64 t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(uint64 t) {cerr << t;}

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

/* clang-format on */
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

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif

  double R = 0.002;
  double K = 5.;

  int nDivs = 10000;
  double Length = 1200;

  double delta_x = (double)(Length / nDivs);

  vector<double> b(nDivs + 1, 0.);
  vector<double> d(nDivs + 1, 0.);
  vector<double> a(nDivs + 1, 0.);
  vector<double> c(nDivs + 1, 0.);

  b[0] = 0;
  d[0] = 1;
  a[0] = 0;
  c[0] = 10 * 10;

  b[nDivs] = 0;
  d[nDivs] = 1;
  a[nDivs] = 0;
  c[nDivs] = 8 * 8;

  for (int i = 1; i < nDivs; i++) {
    b[i] = 1;
    d[i] = -2;
    a[i] = 1;
    c[i] = -2 * R * (delta_x * delta_x) / K;
  }

  vector<double> answer = thomas_algorithm(a, b, c, d);

  freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << nDivs + 1 << endl;
  for (int i = 0; i < answer.size(); i++) {
    cout << sqrt(answer[i]) << " ";
  }
  cout << endl;
  for (int i = 0; i < answer.size(); i++) {
    cout << (double)((double)(i)*Length / (double)(nDivs)) << " ";
  }

  return 0;
}
