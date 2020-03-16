#include "utils/include/btree.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    vector<int> values{4, 1, 3, 2, 5, 6};

    BTree btree(values);
    btree.print();

    return 0;
}