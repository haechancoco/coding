#include <iostream>
using namespace std;

namespace my_namespace {
    int x = 5;
    void print() {
        cout << "Hello from my_namespace" << endl;
    }
}
using namespace my_namespace;

int main(void) {
    int x = 0;
    cout << x;

    return 0;
}