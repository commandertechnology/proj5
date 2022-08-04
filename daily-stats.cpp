#include "daily-stats.hpp"
#include <iostream>
#include <sstream>
#include <string>

// a function to find doubles in text
bool isNumber(std::string str) {
  int decm = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '.') {
      decm++;
    } else if (!isdigit(str[i])) {
      return false;
    }
  }
  if (decm <= 1) {
    return true;
  } else {
    return false;
  }
}

// definitions of DailyStats class

int n;

// Parse function def
bool DailyStats::parse(const std::string &line) {

  // builtin
  std::stringstream ss(line);
  std::string word;
  n = 0;
  while (ss >> word) {
    if (isNumber(word) == true) {
      temperature += stof(word);
      n++;
    } else
      date = word;
  }
  if (n == 0) {
    return false;
  }
  return true;
}

// function to find mean

double DailyStats::mean() { return temperature / n; }

// date getter
std::string DailyStats::getdate() { return date; }
