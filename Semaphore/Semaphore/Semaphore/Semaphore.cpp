#include <iostream>

using namespace std;

int main() {
    int x, y = 0;
    while (cin >> x) {
        cout << x - y << ' ';
        y = x;
    }
}