#include <iostream>
#include <string>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cur_x{ 0 };
    int cur_y{ 0 };
    int dir{ 0 };
    int cnt{ 0 };
    int answer{ -1 };
    bool start = false;

    string com;
    cin >> com;
    
    for(auto c : com) {
        if (c == 'L') {
            dir = (dir + 3) % 4;
        }
        if (c == 'R') {
            dir = (dir + 1) % 4;
        }
        if (c == 'F') {
            start = true;
            cur_x += dx[dir];
            cur_y += dy[dir];
        }
        cnt++;

        if (start && cur_x == 0 && cur_y == 0) {
            answer = cnt;
            break;
        }
    }

    cout << answer;
    // 여기에 코드를 작성해주세요.
    return 0;
}