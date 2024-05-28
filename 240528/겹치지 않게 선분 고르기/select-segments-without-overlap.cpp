#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> lines;

bool cmp(const pair<int, int> a, const pair<int, int> b) {
    if (a.second == b.second) {
        return a.second < b.second;
    }

    return a.second < b.second;
}

int main() {
    cin >> n;
    for (int i{ 0 }; i < n;i ++) {
        int x1, x2;
        cin >> x1 >> x2;
        lines.push_back({x1, x2});
    }

    sort(lines.begin(), lines.end(), cmp);
    
    int cnt{ 1 };
    int end_time = lines[0].second;
    for (int i{ 1 }; i < n; i++) {
        if (end_time < lines[i].first) {
            cnt++;
            end_time = lines[i].second;
        }
    }

    cout << cnt;

    // 여기에 코드를 작성해주세요.
    return 0;
}