#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> v;

void bt(int m) {
    if (m == n) {
        for(auto z : v) {
            cout << z << " ";
        }
        cout << "\n";

        return;
    }

    for(int i{ 1 }; i <= k; i++) {
        v[m] = i;
        bt(m + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n;
    v = vector<int>(n);
    bt(0);

    // 여기에 코드를 작성해주세요.
    return 0;
}