#include "utils/include/string_match.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    std::string str = "ababxbababcadfdsss";
    std::string sub_str = "sss"; //"abcdabd";

    StringMatch string_match;
    auto res = string_match.KMP(str, sub_str);
    std::cout << "res = " << res << std::endl;

    return 0;
}