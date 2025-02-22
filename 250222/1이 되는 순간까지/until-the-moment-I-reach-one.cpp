#include <iostream>

using namespace std;

int N;

int recur_func(const int a) {
    if (a == 1) return 0;

    if (a % 2) return recur_func(a / 3) + 1;
    else return recur_func(a / 2) + 1;
}

int main() {
    cin >> N;

    // Write your code here!
    cout << recur_func(N);

    return 0;
}