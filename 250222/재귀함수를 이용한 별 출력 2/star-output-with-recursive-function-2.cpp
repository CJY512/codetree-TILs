#include <iostream>

using namespace std;

int n;

void print_star(const int m) {
    if (m == 0) return;

    for(int i{ 0 }; i < m; i++) {
        cout << "* ";
    }
    cout << "\n";
    print_star(m - 1);
    for(int i{ 0 }; i < m; i++) {
        cout << "* ";
    }
    cout << "\n";
}

int main() {
    cin >> n;

    // Write your code here!
    print_star(n);

    return 0;
}