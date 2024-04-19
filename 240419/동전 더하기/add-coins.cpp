#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main() {

    cin >> n >> k;
    vector<int> coins(n);
    
    for(int i{ 0 }; i < n; i++) {
        cin >> coins[i];
    }

    int coin_num{ 0 };
    for(int i{ n - 1 }; i >= 0; i--) {
        coin_num += k / coins[i];
        k %= coins[i];
    }

    cout << coin_num;
    // 여기에 코드를 작성해주세요.
    return 0;
}