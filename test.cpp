#include "daily-stats.hpp"
#include <cassert>
#include <iostream>

using namespace std;

bool isClose(double value1, double value2, double epsilon = 1e-4);
void testDailyStats();

int main() {
  testDailyStats();
  return EXIT_SUCCESS;
}

bool isClose(double value1, double value2, double epsilon) {
  return abs(value1 - value2) < epsilon;
}

void testDailyStats() {
  cout << "Start testing the DailyStats class ...\n";
  string line = "6/23/2021 78.48 77.92 74.83 74.27 73.44 71.16 78.21 77.95 "
                "76.12 72.21 71.19 78.46 72.54 77.73 78.86 77.54 73.39 78.43 "
                "73.51 71.11 70.77 73.10 70.63 79.91";
  DailyStats ds;
  assert(ds.parse(line));
  assert(ds.getdate() == "6/23/2021");
  assert(isClose(ds.mean(), 75.0733));
  cout << "All test passed!\n";
}
