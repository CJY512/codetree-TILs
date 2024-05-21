#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    unordered_map<int, int> num_cnt;

    cin >> n >> m;
    while(n--) {
        int num;
        cin >> num;
        num_cnt[num]++;
    }
    while(m--) {
        int idx;
        cin >> idx;
        cout << num_cnt[idx] << " ";
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}