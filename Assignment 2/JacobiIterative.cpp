#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <unistd.h>
#include <vector>
void write_csv(std::string filename, std::vector<std::vector<double>> vals) {
  // Make a CSV file with one column of integer values
  // filename - the name of the file
  // colname - the name of the one and only column
  // vals - an integer vector of values

  // Create an output filestream object
  std::ofstream myFile(filename);

  // Send the column name to the stream
  /* myFile << colname << "\n"; */

  // Send data to the stream
  for (int i = 0; i < vals.size(); i++) {
    for (int j = 0; j < vals[0].size(); j++) {
      myFile << vals[i][j] << ",";
    }
    myFile << "\n";
  }

  // Close the file
  myFile.close();
}

int main() {

  int lenX = 300;
  int lenY = 100;

  int nDivX = 31;
  int nDivY = 11;

  std::vector<std::vector<double>> hOld(nDivY, std::vector<double>(nDivX, 0));

  std::vector<std::vector<double>> hNew(nDivY, std::vector<double>(nDivX, 0));

  double error = 1.;

  for (int i = 0; i < nDivY; i++) {
    for (int j = 0; j < nDivX; j++) {
      if (j == 0) {
        hOld[i][j] = 70. - 2 * i / (nDivY - 1.);
        hNew[i][j] = 70. - 2 * i / (nDivY - 1.);
      }
      if (j == nDivX - 1) {
        hOld[i][j] = 69. - 4. * i / (nDivY - 1.);
        hNew[i][j] = 69. - 4. * i / (nDivY - 1.);
      }
    }
  }
  while (error > 10e-6) {

    error = 0;
    /* for (int i=0; i<nDivY; i++) { */
    /* 	hNew[i][0] */
    /* } */
    for (int i = 1; i < nDivY - 1; i++) {
      for (int j = 1; j < nDivX - 1; j++) {

        hNew[i][j] = 0.25 * (hOld[i - 1][j] + hOld[i + 1][j] +
                             hOld[i][j + nDivX] + hOld[i][j - nDivX]);
        error += fabs(hNew[i][j] - hOld[i][j]);
      }
    }
    std::cout << error << std::endl;
    std::copy(std::begin(hNew), std::end(hNew), std::begin(hOld));
  }

  for (int i = 0; i < nDivY; i++) {
    for (int j = 0; j < nDivX; j++) {
      if (i == 0) {
        hNew[i][j] = hNew[i + 1][j];
      }
      if (i == nDivY - 1) {
        hNew[i][j] = hNew[i - 1][j];
      }
    }
  }

  for (int i = 0; i < nDivY; i++) {
    for (int j = 0; j < nDivX; j++) {
      std::cout << hNew[i][j] << " ";
    }
    std::cout << std::endl;
  }

  write_csv("Output.csv", hNew);
}
