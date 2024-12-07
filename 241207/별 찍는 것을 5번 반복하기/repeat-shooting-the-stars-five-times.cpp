#include <iostream>
using namespace std;

void PrintStarsByNum(const int num) {
    for (int i{ 0 }; i < num; i++) {
        cout << "*";
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int row{ 5 };
    int col{ 10 };
    for (int i{ 0 }; i < row; i++) {
        PrintStarsByNum(10);
        cout << "\n";
    }
    return 0;
}