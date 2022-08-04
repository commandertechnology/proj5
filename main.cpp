
#include "daily-stats.hpp"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

// protype of functions
void menu();
void queryByDate(DailyStats *obj, std::string &date_key, int size);
std::string queryByHeighestTemp(DailyStats *obj, int szie);
void fullReport(DailyStats *obj, int size);

// main function
int main() {
  // array of objects size 31;
  const int size = 31;
  DailyStats stats[size];
  std::string fileName;
  bool exit = false;
  // getting file name
  do {
    std::cout << "\nPlease enter file name of your DataFile: ";
    std::cin >> fileName;

    std::ifstream readF;
    std::string line;
    readF.open(fileName, std::ios::in);
    int i = 0;

    // checking file exist or not
    if (!readF) {
      std::cout << "Cannot open the file, please try again.  ";
      exit = true;

    }

    else {

      while (!readF.eof()) {
        // reading file line by line
        getline(readF, line);

        if (stats[i].parse(line) == false) {
          std::cout << "File data is not in valid format, please try again ";
          exit = true;
          break;
        }
        i++;
      }
      int option;

      // loop to show again
      do {
        menu();

        std::cin >> option;

        // checking position choosed

        if (option == 1) {

          std::string new_date;
          std::cout << "Please enter a date in format like mm/dd/yyyy : ";
          std::cin >> new_date;
          queryByDate(stats, new_date, size);
        }

        // option 2
        else if (option == 2) {
          std::cout << "The date with the heighest average temperature is : "
                    << queryByHeighestTemp(stats, size);
        }

        // option 3
        else if (option == 3) {
          fullReport(stats, size);
        }

        // exit option
        else if (option == 4) {
          option = 4;
          exit = false;
        }

        // invalid option
        else {
          std::cout << "Please choose the correct option ,";
        }

      } while (option != 4); // end of inner do while loop

      // file closed
      readF.close();
    }

  } while (exit == true); // end of outer loop
}

// Mmenu function to show mmenu for user
void menu() {
  std::cout << "\nTemperature Analysis app Menu \n";
  std::cout << "1. Query by date \n";
  std::cout << "2. Query date by heighest temperature \n";
  std::cout << "3. Print full report \n";
  std::cout << "4. Exit program \n";
  std::cout << "Please choose an option : ";
}

// function to find by date
void queryByDate(DailyStats *obj, std::string &date_key, int size) {
  bool found = false;
  for (int i = 0; i < size; i++) {
    if (date_key == obj[i].getdate()) {

      // showing date and temperature with 2 decimals
      std::cout << "Found the date " << obj[i].getdate()
                << " with Average teperature at: " << std::setprecision(2)
                << std::fixed << obj[i].mean() << "\n";
      found = true;
      break;
    }
  }
  if (found == false)
    std::cout << "\nDate not found!";
}

// hieghes temperature date
std::string queryByHeighestTemp(DailyStats *obj, int size) {
  std::string d;
  double max = obj[0].mean();
  for (int i = 0; i < size; i++) {
    if (obj[i].mean() > max) {
      max = obj[i].mean();
      d = obj[i].getdate();
    }
  }
  return d;
}

// function to show full report
void fullReport(DailyStats *obj, int size) {
  std::cout << " Date \t\t Mean \n";
  for (int i = 0; i < size; i++) {

    // avoiding garbage values
    if (obj[i].mean() != 0.0)

      std::cout << obj[i].getdate() << "  " << std::setprecision(2)
                << std::fixed << obj[i].mean() << std::endl;
  }
}
