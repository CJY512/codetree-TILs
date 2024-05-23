#include <iostream>
#include <vector>

int n;

void bt(int rest, int& result) {
    if (rest == 0) {
        result++;
        return;
    }

    for (int i{ 1 }; i <= n; i++) {
        if (rest < i) break;
        bt(rest - i, result);
    }
}

int dp[15];

void make_dp() {
    for (int i{ 1 }; i <= 10; i ++) {
        for (int j{ 1 }; j < i && j <= 4; j++) {
            dp[i] += dp[i - j];
        }
        if (i <= 4) dp[i] += 1;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    dp[0] = 0;
    make_dp();
    int ans{ 0 };
    bt(n, ans);

    // std::cout << ans;
    std::cout << dp[n];

    // 여기에 코드를 작성해주세요.
    return 0;
}