/**
 * 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front
的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

输入:
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]

输入:
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
*/

#include <deque>
#include <iostream>
#include <mutex>
#include <queue>

class MaxQueue {
   public:
    MaxQueue() { ; }

    int max_value() {
        std::lock_guard<std::mutex> lock(mtx_);
        if (!deque_.empty()) {
            return deque_.front();
        } else {
            return -1;
        }
    }

    void push_back(int value) {
        std::lock_guard<std::mutex> lock(mtx_);
        // 双端队列中只存储比value大的元素，则始终deque_是递减的
        while (!deque_.empty() && deque_.back() < value) {
            deque_.pop_back();
        }
        deque_.push_back(value);
        queue_.push(value);
    }

    int pop_front() {
        std::lock_guard<std::mutex> lock(mtx_);
        if (queue_.empty()) {
            return -1;
        }

        int ret = queue_.front();
        if (ret == deque_.front()) {
            deque_.pop_front();
        }

        queue_.pop();
        return ret;
    }

   private:
    inline int empty() {
        std::lock_guard<std::mutex> lock(mtx_);
        return deque_.empty();
    }


   private:
    std::deque<int> deque_;
    std::queue<int> queue_;

    int max_value_ = INT32_MIN;
    std::mutex mtx_;

    const int kMaxElementsNum = 10000;
    const int kEachElementsNum = 100;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main(int argc, char* argv[]) {
    MaxQueue* obj = new MaxQueue();

    int param_1 = obj->max_value();
    std::cout << "param_1 = " << param_1 << std::endl;
    int value = 3;
    obj->push_back(value);
    int param_3 = obj->pop_front();
    std::cout << "param_3 = " << param_3 << std::endl;

    return 0;
}
