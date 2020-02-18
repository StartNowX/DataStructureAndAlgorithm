/**
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1)额外空间的条件下完成。
 * nums=[1, 1, 2], return length = 2, modify nums as [1, 2]
 * nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4], return length = 5, modify nums as [0, 1, 2, 3, 4]
*/

#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates(vector<int>& nums) {
    // int length = nums.size();

    // // 迭代器指向的是数组末端元素的下一个，即指到一个不存在的元素，起到哨兵的作用
    // for(vector<int>::iterator it = nums.end() - 1; it != nums.begin(); --it) {
    //     int last_value = *(it - 1);
    //     if(last_value == *it) {
    //         nums.erase(it);
    //     }
    // }

    // 其实，按题目意思，不需要移除重复元素后的元素，最后根据返回的新的数组的长度进行切片即可
    int size = !nums.empty();
    for(auto ele : nums) {
        if(ele != nums[size - 1]) {
            nums[size++] = ele;
        }
    }


    return size;
}

int main(int argc, char* argv[]) {

    vector<int> target_vect{1, 1, 2};
    // vector<int> target_vect{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // vector<int> target_vect(1, 2);

    int length = target_vect.size();
    length = remove_duplicates(target_vect);

    cout << "result: length = " << length << ", elements: ";
    for(vector<int>::iterator it = target_vect.begin(); it != target_vect.begin() + length; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}