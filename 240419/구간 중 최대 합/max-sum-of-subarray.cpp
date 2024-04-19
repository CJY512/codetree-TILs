#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main() {

    cin >> n >> k;
    vector<int> arr(n);

    for(int i{ 0 }; i < n; i++) {
        cin >> arr[i];
    }

    int max_sum{ 0 };
    for(int i { 0 }; i < k; i++) {
        max_sum += arr[i];
    }

    int partial_sum = max_sum;
    for(int i{ k }; i < n; i++) {
        partial_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, partial_sum);
    }

    cout << max_sum;
    // 여기에 코드를 작성해주세요.
    return 0;
}