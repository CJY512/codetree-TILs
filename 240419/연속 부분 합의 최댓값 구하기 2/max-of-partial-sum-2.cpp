#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;

int main() {
    
    cin >> n;
    vector<int> arr(n);

    for(int i{ 0 };i < n;i++) {
        cin >> arr[i];
    }

    int max_sum = INT_MIN;
    int sum{ 0 };
    for(int i{ 0 }; i < n;i++) {
        sum += arr[i];
        max_sum = max(max_sum, sum);
        if(sum < 0) sum = 0;
    }

    cout << max_sum;
    // 여기에 코드를 작성해주세요.
    return 0;
}