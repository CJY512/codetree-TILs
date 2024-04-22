#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {

    cin >> n;
    vector<int> prices(n);

    for(int i{ 0 }; i < n; i++) {
        cin >> prices[i];
    }

    int max_profit{ 0 };
    int min_price = prices[0];
    for(int i{ 1 }; i < n; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        else {
            max_profit = max(max_profit, prices[i] - min_price);
        }
    }

    cout << max_profit;
    // 여기에 코드를 작성해주세요.
    return 0;
}