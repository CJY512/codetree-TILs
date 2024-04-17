#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i{ 0 }; i < n; i++) {
        cin >> arr[i];
    }

    int max_sum = INT_MIN;
    for(int i{ 0 }; i < n - 2; i++) {
        for(int j{ i + 2 }; j < n; j++) {
            max_sum = max(max_sum, arr[i] + arr[j]);
        }
    }

    cout << max_sum;
    // 여기에 코드를 작성해주세요.
    return 0;
}