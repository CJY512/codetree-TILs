#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n;

struct Meeting {
    int s;
    int e;

    Meeting(int S, int E) : s(S), e(E) {}

    bool operator<(const Meeting m) const {
        if (this->e == m.e) {
            return this->s < m.s;
        }

        return this->e > m.e;
    }
};

int main() {

    cin >> n;

    priority_queue<Meeting> pq;

    for(int i{ 0 };i < n;i++) {
        int s, e;
        cin >> s >> e;
        Meeting m{s, e};
        pq.push(m);
    }

    int max_meeting_schedule = 0;

    int cur_end_time = 0;
    while(!pq.empty()) {
        Meeting m = pq.top(); pq.pop();
        if(m.s < cur_end_time) continue;

        max_meeting_schedule++;
        cur_end_time = m.e;
    }

    cout << max_meeting_schedule;
    // 여기에 코드를 작성해주세요.
    return 0;
}