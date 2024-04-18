#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    
    cin >> n;
    vector<int> for_sum(n);
    vector< vector<int> > arr(n, vector<int>(4, 0));

    for(int i{ 0 }; i < n; i++) {
        int tmp;
        cin >> tmp;
        for_sum[i] = tmp;
        for(int j{ 0 }, mod{ 1000 }; j < 4; j++, mod /= 10) {
            arr[i][j] = tmp / mod;
            tmp %= mod;
        }
    }

    int max_sum = -1;
    for(int i{ 0 }; i < n - 2; i++) {
        for(int j{ i + 1 }; j < n - 1; j++) {
            for(int k{ j + 1 }; k < n; k++) {
                if(arr[i][0] + arr[j][0] + arr[k][0] < 10 &&
                arr[i][1] + arr[j][1] + arr[k][1] < 10 &&
                arr[i][2] + arr[j][2] + arr[k][2] < 10 &&
                arr[i][3] + arr[j][3] + arr[k][3] < 10) {
                    max_sum = max(max_sum, for_sum[i] + for_sum[j] + for_sum[k]);
                }
            }
        }
    }

    cout << max_sum;
    // 여기에 코드를 작성해주세요.
    return 0;
}