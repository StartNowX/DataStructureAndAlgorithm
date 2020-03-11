#ifndef TIME_LOG_
#define TIME_LOG_

#include <string>
#include <ctime>
#include <iostream>
#include <chrono>

class TimeLog {
   public:
    TimeLog(std::string& name) : module_name(name) { start = std::chrono::high_resolution_clock::now(); }
    TimeLog(const std::string& name) : module_name(name) { start = std::chrono::high_resolution_clock::now(); }

    TimeLog() = delete;
    TimeLog(const TimeLog& timelog) = delete;

    ~TimeLog() {
        std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
        // std::ratio<1, 1000>, ms
        // std::ratio<1, 1>, s
        // std::ratio<60, 1>, minute
        std::chrono::duration<double, std::ratio<1, 1000>> duration = end - start;
        std::cout << "    { " << module_name << " costs " << duration.count() << " ms. }" << std::endl;
        // std::cout << "    { " << module_name << " costs " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms. }"
        //           << std::endl;
    }

   private:
    std::string module_name;
    // std::clock_t start;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

#endif  // !TIME_LOG_