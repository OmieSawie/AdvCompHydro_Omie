#include "matplotlibcpp.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

namespace plt = matplotlibcpp;

int main() {
  freopen("./outputConventration.txt", "r", stdin);
  // freopen("output.txt","w",stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int nDivs = 0;
  std::cin >> nDivs;
  std::vector<double> heights(nDivs);
  for (int i = 0; i < nDivs; i++) {
    std::cin >> heights[i];
  }
  std::vector<double> distance(nDivs);
  for (int i = 0; i < nDivs; i++) {
    // std::cin >> distance[i];
    distance[i] = i;
  }

  plt::plot(distance, heights, {{"label", "Concentration"}});
  double maxHeightIdx =
      (std::max_element(heights.begin(), heights.end()) - heights.begin());

  double maxHeight = heights[maxHeightIdx],
         maxHeightDist = distance[maxHeightIdx];

  std::cout << "Max Conc is " << maxHeight << " at " << maxHeightDist
            << std::endl;
  /* plt::plot(maxHeightDist, maxHeight, "0", {{"label", "MaxHeight"}}); */
  plt::xlabel("Distance");
  plt::ylabel("Concentration");

  plt::legend();
  plt::show();
}
