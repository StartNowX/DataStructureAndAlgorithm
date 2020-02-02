/**
 * Pascal's Triangle
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Generate(int num_rows) {
    vector<vector<int> > pascal_tri;

    if (0 == num_rows) {
        return pascal_tri;
    }

    vector<int> tmp_vec{1};
    pascal_tri.emplace_back(tmp_vec);
    if (1 == num_rows) {
        return pascal_tri;
    }

    // i代表行数，等于index+1
    for (int i = 2; i <= num_rows; ++i) {
        vector<int> single_row(i, 0);
        for(int j = 0; j < i; ++j) {
            if (j == 0) {
                single_row[j] += pascal_tri[i-2][0];
            } else if (j == i - 1) {
                single_row[j] += pascal_tri[i-2][i-2];
            } else {
                single_row[j] = pascal_tri[i-2][j-1] + pascal_tri[i-2][j];
            }
        }
        pascal_tri.emplace_back(single_row);
    }
}

// LeetCode vticn 
// 从后向前遍历数组，只操作原数组
vector<vector<int>> GenerateVticn(int num_rows) {
    vector<int> vec{1};
    vector<vector<int> > res;

    while (num_rows-- > 0) {
        // emplace_back替换push_back, 更减少耗时
        res.emplace_back(vec);

        for (int i = vec.size() - 1; i > 0; --i) {
            vec[i] += (i - 1 >= 0) ? vec[i-1] : 0;
        }
        vec.emplace_back(1);
    }
    return res;
}

int main(int argc, char* argv[]) {
    int num_row = 5;

    vector<vector<int>> res;

    res = GenerateVticn(num_row);

    for (vector<vector<int>>::iterator it = res.begin(); it != res.end();
            ++it) {
        for (vector<int>::iterator it_each = (*it).begin();
                it_each != (*it).end(); ++it_each) {
            cout << *it_each << " ";
        }
        cout << endl;
    }

    return 0;
}