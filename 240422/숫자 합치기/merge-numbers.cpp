#include <iostream>
#include <queue>
using namespace std;

int n;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;

    for(int i{ 0 }; i < n;i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int min_sum = 0;
    while(1) {
        int a, b;
        if (pq.empty()) break;
        a = pq.top(); pq.pop();
        if (pq.empty()) break;
        b = pq.top(); pq.pop();

        int sum = a + b;
        min_sum += sum;
        pq.push(sum);
    }

    cout << min_sum;

    // 여기에 코드를 작성해주세요.
    return 0;
}