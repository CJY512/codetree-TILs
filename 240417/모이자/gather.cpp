#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> A;

    cin >> n;
    for(int i{0}; i < n; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    int min_distance = INT_MAX;
    for(int to{ 0 }; to < n; to++) {
        int distance = 0;
        for (int from{ 0 }; from < n; from++) {
            distance += abs(from - to) * A[from];
        }
        min_distance = min(min_distance, distance);
    }

    cout << min_distance;
    // 여기에 코드를 작성해주세요.
    return 0;
}