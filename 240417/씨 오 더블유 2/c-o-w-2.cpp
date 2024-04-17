#include <iostream>
#include <string>
using namespace std;

int main() {

    int len;
    string s;
    cin >> len >> s;

    int cnt = 0;
    for(int i{ 0 }; i < len - 2; i++) {
        if(s[i] == 'C') {
            for(int j{ i + 1 }; j < len - 1; j++) {
                if(s[j] == 'O') {
                    for(int k{ j + 1 }; k < len; k++) {
                        if(s[k] == 'W') cnt++;
                    }
                }
            }
        }
    }    
    cout << cnt;
    // 여기에 코드를 작성해주세요.
    return 0;
}