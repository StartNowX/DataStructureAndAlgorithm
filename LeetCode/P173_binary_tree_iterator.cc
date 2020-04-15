#include <iostream>

class A {
   private:
    int value_;

   public:
    A(int a) : value_(a) {}
    A(const A& other) { value_ = other.value_ }
};


int main(int argc, char* argv[]) { return 0; }