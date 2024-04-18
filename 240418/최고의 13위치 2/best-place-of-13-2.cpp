#include <iostream>
#include <climits>
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

    int max_sum = INT_MIN;
    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < n - 2; j++) {
            for(int k{ i }; k < n; k++) {
                for(int l{ j }; l < n - 2; l++) {
                    if(i == k && l <= j + 2) continue;
                    max_sum = max(max_sum, arr[i][j] + arr[i][j + 1] + arr[i][j + 2]
                                            + arr[k][l] + arr[k][l + 1] + arr[k][l + 2]);
                }
            }
        }
    }

    cout << max_sum;   
    // 여기에 코드를 작성해주세요.
    return 0;
}