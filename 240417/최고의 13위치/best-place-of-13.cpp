#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[25][25];
    
    cin >> n;
    for(int i{0};i<n;i++) {
        for(int j{0};j<n;j++) {
            cin >> arr[i][j];
        }
    }

    int max_coin = 0;
    for(int i{0};i<n;i++) {
        for(int j{0};j<n-2;j++) {
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            max_coin = max(max_coin, sum);
        }
    }

    cout << max_coin;
    // 여기에 코드를 작성해주세요.
    return 0;
}