/**
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。在杨辉三角中，每个数是它左上方和右上方的数的和
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> GetRow(int row_index) {
    vector<int> vec{1};
    while (row_index-- > 0) {
        for (int i = vec.size() - 1; i > 0; --i) {
            vec[i] += (i - 1 >= 0) ? vec[i-1] : 0; 
        }
        vec.emplace_back(1);
    }
    return vec;
}

vector<int> GetRowFast(int row_index) {
    vector<int> res;
    // 和上一版对比，减少了不停的调用vec.size()操作
    for (int i = 0; i <= row_index; ++i) {
        res.emplace_back(1);
        for (int j = i - 1; j > 0; --j) {
            res[j] += res[j - 1];
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    int num_row = 2;

    vector<int> res;

    res = GetRowFast(num_row);

    for (vector<int>::iterator it_each = res.begin(); it_each != res.end(); ++it_each) {
        cout << *it_each << " ";
    }
    cout << endl;

    return 0;
}