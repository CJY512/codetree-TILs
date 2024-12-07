#include <iostream>
using namespace std;

void PrintSquare(const int len) {
    int elem{ 1 };
    for(int i{ 0 }; i < len; i++) {
        for(int j{ 0 }; j < len; j++) {
            cout << elem << " ";
            elem = (elem == 9) ? 1 : ++elem;
        }
        cout << "\n";
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int input;
    cin >> input;
    PrintSquare(input);
    return 0;
}