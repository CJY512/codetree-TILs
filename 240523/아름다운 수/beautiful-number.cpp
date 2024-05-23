#include <iostream>

int n;

void bt(int rest, int& result) {
    if (rest == 0) {
        result++;
        return;
    }

    for (int i{ 1 }; i <= n; i++) {
        if (rest < i) continue;
        bt(rest - i, result);
    }
}

int main() {

    std::cin >> n;

    int ans{ 0 };
    bt(n, ans);

    std::cout << ans;

    // 여기에 코드를 작성해주세요.
    return 0;
}