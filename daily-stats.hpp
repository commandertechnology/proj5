#ifndef DAILY_STATS_HPP
#define DAILY_STATS_HPP

#include <iostream>
class DailyStats{
 std::string date;
 double temperature;
 public:
   DailyStats(){
      date="\0";
      temperature=0.0;
     } 
     
  bool parse(const std::string& line);
  double mean();
  std::string  getdate();
} ;

#endif //DAILY_STATS_HPP