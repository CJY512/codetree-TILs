#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, ans{ 0 };
    unordered_map<string, int> um;

    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        um[s]++;
        if(ans < um[s]) {
            ans = um[s];
        }
    }

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}