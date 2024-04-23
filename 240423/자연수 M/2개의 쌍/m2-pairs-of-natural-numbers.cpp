#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

using pii = pair<int, int>;

int n, m;

struct Mynum {
    int x;
    int y;

    Mynum() : x(0), y(0) {}
    Mynum(int X, int Y) : x(X), y(Y) {}
    bool operator<(const Mynum z) const {
        return this->y < z.y;
    }
};

int main() {

    cin >> n;
    vector<Mynum> arr(n);
    for(int i{ 0 };i < n;i++) {
        int x, y;
        cin >> x >> y;
        Mynum mynum{x, y};
        arr[i] = mynum;
    }
    sort(arr.begin(), arr.end());

    int i{ 0 }, j{ n - 1 };
    int max_sum{ 0 };
    while(i < j) {
        max_sum = max(max_sum, arr[i].y + arr[j].y);
        arr[i].x -= 1;
        arr[j].x -= 1;
        if(arr[i].x == 0) i++;
        if(arr[j].x == 0) j--;
    }

    cout << max_sum;
    // 여기에 코드를 작성해주세요.
    return 0;
}