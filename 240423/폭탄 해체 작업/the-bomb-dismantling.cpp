#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Bomb {
    int score;
    int time;

    Bomb(int sc, int t) : score(sc), time(t) {}
    bool operator<(const Bomb b) const {
        if (this->score == b.score) {
            return this->time < b.time;
        }
        return this->score < b.score;
    }
};

int main() {

    int n;
    cin >> n;
    vector<bool> sch(n);
    priority_queue<Bomb> bombs;

    for(int i{ 0 };i < n;i++) {
        int sc, t;
        cin >> sc >> t;
        Bomb b{sc, t};
        bombs.push(b);
    }

    int max_score{ 0 };
    for(int game_time{ 1 }; game_time <= n; game_time++) {
        Bomb bomb = bombs.top(); bombs.pop();
        for(int i{ bomb.time }; i > 0; i--) {
            if (!sch[i]) {
                sch[i] = true;
                max_score += bomb.score;    
                break;
            }
        }
    }

    cout << max_score;
    // 여기에 코드를 작성해주세요.
    return 0;
}