#include <iostream>
using namespace std;

int GetGreatestCommonDivisor(int a, int b) {
    if (a < b) 
        swap(a, b);
    
    while(a % b) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    return b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << GetGreatestCommonDivisor(a, b);
    // 여기에 코드를 작성해주세요.
    return 0;
}