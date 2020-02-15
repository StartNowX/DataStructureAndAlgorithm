#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <vector>

template <typename T>
class Utils {
   public:
    Utils(){};
    ~Utils(){};

    void PrintVector(std::vector<T>& vec) {
        std::cout << "vec elements are: ";
        for (auto ele : vec) {
            std::cout << ele << " ";
        }
        std::cout << std::endl;
    }

    void PrintVector2D(std::vector<std::vector<T>>& vec) {
        std::cout << "vec elements are: ";
        for (auto ele : vec) {
            std::cout << std::endl;
            for (auto inner_ele : ele) {
                std::cout << inner_ele << " ";
            }
        }
        std::cout << std::endl;
    }

   private:
    //
    std::vector<T> utils_vec_;
};

#endif  // UTILS_H_