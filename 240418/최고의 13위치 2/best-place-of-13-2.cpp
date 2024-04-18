#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[25][25];

int main() {

    cin >> n;

    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> three_sum(n * n);

    int idx = 0;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n - 2; j++) {
            three_sum[idx++] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
        }
        idx += n;
    }

    sort(three_sum.begin(), three_sum.end(), greater<>());

    cout << three_sum[0] + three_sum[1];
    // 여기에 코드를 작성해주세요.
    return 0;
}