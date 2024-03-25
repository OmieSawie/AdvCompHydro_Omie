#include "matplotlibcpp.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

namespace plt = matplotlibcpp;

/* int main() { */
/*   freopen("output.txt", "r", stdin); */
/*   // freopen("output.txt","w",stdout); */
/*   std::ios_base::sync_with_stdio(false); */
/*   std::cin.tie(NULL); */
/*   int nDivs = 0; */
/*   std::cin >> nDivs; */
/*   std::vector<double> heights(nDivs); */
/*   for (int i = 0; i < nDivs; i++) { */
/*     std::cin >> heights[i]; */
/*   } */
/*   std::vector<double> distance(nDivs); */
/*   for (int i = 0; i < nDivs; i++) { */
/*     std::cin >> distance[i]; */
/*   } */

/*   plt::plot(distance, heights, {{"label", "Height"}}); */
/*   double maxHeightIdx = */
/*       (std::max_element(heights.begin(), heights.end()) - heights.begin());
 */

/*   double maxHeight = heights[maxHeightIdx], */
/*          maxHeightDist = distance[maxHeightIdx]; */

/*   std::cout << "Max Height is " << maxHeight << " at " << maxHeightDist */
/*             << std::endl; */
/*   /1* plt::plot(maxHeightDist, maxHeight, "0", {{"label", "MaxHeight"}}); *1/
 */
/*   plt::xlabel("Distance"); */
/*   plt::ylabel("Height"); */

/*   plt::legend(); */
/*   plt::show(); */
/* } */

int main() {
  // Create a 3D axes object.
  plt::Axes3D axes;

  // Create a grid of x and y values.
  std::vector<double> x = {1, 2, 3, 4, 5};
  std::vector<double> y = {1, 2, 3, 4, 5};

  // Create a 2D array of z values.
  std::vector<std::vector<double>> z = {{1, 2, 3, 4, 5},
                                        {2, 3, 4, 5, 6},
                                        {3, 4, 5, 6, 7},
                                        {4, 5, 6, 7, 8},
                                        {5, 6, 7, 8, 9}};

  // Plot the surface.
  axes.plot_surface(x, y, z);

  // Set the title of the plot.
  axes.set_title("Surface Plot");

  // Show the plot.
  plt::show();

  return 0;
}
