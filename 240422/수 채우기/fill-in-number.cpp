#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 100000

int n;
int dp[MAX_N + 10];

void init() {
    dp[0] = 0;
    for(int i{ 1 }; i <= n; i++) {
        dp[i] = INT_MAX;
    }
}
int main() {

    cin >> n;
    init();
    for(int i{ 0 }; i <= n; i++) {
        if (dp[i] == INT_MAX) continue;
        dp[i + 2] = min(dp[i] + 1, dp[i + 2]);
        dp[i + 5] = min(dp[i] + 1, dp[i + 5]);
    }

    cout << (dp[n] == INT_MAX ? -1 : dp[n]);
    
    // 여기에 코드를 작성해주세요.
    return 0;
}