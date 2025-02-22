#include <iostream>
#include <cmath>

using namespace std;

int N;

int main() {
    cin >> N;

    // Write your code here!
    int quotient{ N }, remainder;
    int answer{ 0 };
    while(1) {
        remainder = quotient % 10;
        quotient = quotient / 10;
        answer += pow(remainder, 2);
        if (!quotient) break;
    }
    cout << answer;

    return 0;
}