#include <iostream>

using namespace std;

int N;

int fbn(const int a) {
    if (a == 1 || a == 2) return 1;
    return fbn(a - 1) + fbn(a - 2);
}

int main() {
    cin >> N;

    // Write your code here!
    cout << fbn(N);

    return 0;
}