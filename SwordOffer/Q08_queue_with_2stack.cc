/**
 * 用两个栈实现一个队列
 */

#include <iostream>
#include <stack>

using namespace std;

class CQueue {
   public:
    CQueue() {}

    void appendTail(int value) { stack_in.push(value); }

    int deleteHead() {
        int res = -1;
        if (!stack_out.empty()) {
            res = stack_out.top();
            stack_out.pop();
        } else if (!stack_in.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
            res = stack_out.top();
            stack_out.pop();
        }
        return res;
    }

   private:
    std::stack<int> stack_in;
    std::stack<int> stack_out;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(int argc, char* argv[]) {
    CQueue* obj = new CQueue();

    int value = 3;
    obj->appendTail(value);
    obj->appendTail(5);
    int param_2 = obj->deleteHead();
    std::cout << "param_2 = " << param_2 << std::endl;

    obj->appendTail(15);
    param_2 = obj->deleteHead();
    std::cout << "param_2 = " << param_2 << std::endl;

    return 0;
}