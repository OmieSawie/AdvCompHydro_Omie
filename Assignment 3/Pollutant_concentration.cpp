#include <bits/stdc++.h>
using namespace std;

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

  freopen("outputProfile.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double E = 100, k = 0.0001;

  int nDivs = 0;
  cin >> nDivs;
  nDivs = nDivs * 8 / 18;
  double Length = 18000. * 8 / 18;

  double delta_x = (double)(Length / nDivs);

  vector<double> b(nDivs + 1, 0.);
  vector<double> d(nDivs + 1, 0.);
  vector<double> a(nDivs + 1, 0.);
  vector<double> c(nDivs + 1, 0.);
  vector<double> V(nDivs + 1, 0.);
  vector<double> y(nDivs + 1, 0.);

  for (int i = 0; i < nDivs; i++) {
    cin >> y[i];
  }
  for (int i = 0; i < nDivs; i++) {
    cin >> V[i];
  }

  // b[nDivs] = 0;
  // d[nDivs] = 1;
  // a[nDivs] = 0;
  // c[nDivs] = 0.01;
  b[0] = 0;
  d[0] = 1;
  a[0] = 0;
  c[0] = 0.005;

  b[nDivs] = 0;
  d[nDivs] = 1;
  a[nDivs] = 0;
  c[nDivs] = 0.01;

  for (int i = 1; i < nDivs; i++) {
    b[i] = (E / (delta_x * delta_x)) - (V[i] / (2 * delta_x));
    d[i] = (2 * E / (delta_x * delta_x)) + (k);
    a[i] = (E / (delta_x * delta_x)) - (V[i] / (2 * delta_x));
    c[i] = 0;
  }

  vector<double> answer = thomas_algorithm(a, b, c, d);

  freopen("outputConventration.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << nDivs + 1 << endl;
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < answer.size(); i++) {
    cout << (double)((double)(i)*Length / (double)(nDivs)) << " ";
  }

  return 0;
}
