#pragma once

#include <string>
#include <vector>

class StringMatch {
   public:
    StringMatch() {}
    ~StringMatch() {}

    bool KMP(const std::string& match_str, const std::string& candidate_str);

   private:
    void MakeNext(const std::string& candidate_str);

   private:
    // std::string match_str_;
    // std::string candidate_substr_;
    std::vector<int> next_table_; /* data */
};
