#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;

int main() {

    cin >> n;
    vector<int> popu;

    for(int i{0};i<n;i++) {
        int tmp;
        cin >> tmp;
        popu.push_back(tmp);
    }

    int min_sum = INT_MAX;

    for(int i{0};i<n;i++) {
        int sum = 0;
        for(int j{0};j<n;j++) {
            if (i == j) continue;
            if (i < j) {
                sum += (j - i) * popu[j];
            }
            else if (j < i) {
                sum += (n + j - i) * popu[j];
            }
        }

        min_sum = min(min_sum, sum);
    }

    cout << min_sum;

    // 여기에 코드를 작성해주세요.
    return 0;
}