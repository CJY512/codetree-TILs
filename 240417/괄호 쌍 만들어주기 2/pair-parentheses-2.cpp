#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;
    cin >> s;
    int len = s.length();

    int cnt = 0;
    for(int i{0};i < len - 1; i++) {
        if(s[i] == '(' && s[i + 1] == '(') {
            for(int j{i + 2}; j < len - 1; j++) {
                if(s[j] == ')' && s[j + 1] == ')') cnt++;
            }
        }
    }

    cout << cnt;
    // 여기에 코드를 작성해주세요.
    return 0;
}