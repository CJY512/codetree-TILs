#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int len = s.length();
    bool all_one = true;
    for(int i{0};i<len;i++) {
        if(s[i] == '0') {
            all_one = false;
            s[i] = '1';
            break;
        }
    }
    if(all_one) {
        s[len-1] = '0';
    }

    int sum = 0;
    int mul = 1;
    for(int i{len - 1}; i >= 0 ; i--) {
        if (s[i] == '1') sum += mul;

        mul *= 2;
    } 
    cout << sum;
    // 여기에 코드를 작성해주세요.
    return 0;
}