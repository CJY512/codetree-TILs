#include <iostream>
using namespace std;

int n;
int x[105];
int y[105];

int main() {

    cin >> n;

    for(int i{0};i<n;i++) {
        cin >> x[i] >> y[i];
    }
    
    int total_dist = 0;
    for(int i{1}; i < n; i++) {
        total_dist += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    }

    int max_save_dist = 0;
    for(int i{1}; i < n - 1; i++) {
        int dist = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1])
                    + abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1])
                    - ( abs(x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]) );
        max_save_dist = max(max_save_dist, dist);
    }

    cout << total_dist - max_save_dist;
    // 여기에 코드를 작성해주세요.
    return 0;
}