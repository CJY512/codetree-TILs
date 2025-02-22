#include <iostream>

using namespace std;

int N;

void recur_func(const int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    recur_func(n - 1);
    cout << n << " ";
}

int main() {
    cin >> N;

    // Write your code here!
    recur_func(N);

    return 0;
}