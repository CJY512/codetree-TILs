#include <iostream>
using namespace std;
#define START_POS 1002

int board[2005][2005];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};

bool oob(const int x, const int y) {
    return x < 0 || y < 0 || x >= 2004 || y >= 2004;
}

int GetDir(char dir) {
    if (dir == 'W') {
        return 0;
    } else if (dir == 'S') {
        return 1;
    } else if (dir == 'N') {
        return 2;
    } else if (dir == 'E') {
        return 3;
    } else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cur_x = START_POS;
    int cur_y = START_POS;
    int cnt{ 0 };
    int answer{ -1 };

    int n;
    cin >> n;

    char dir;
    int move_amount;
    for(int i{ 0 };i < n; i++) {
        cin >> dir >> move_amount;
        int dir_num = GetDir(dir);
        for (int j{ 0 }; j < move_amount; j++) {
            cur_x += dx[dir_num];
            cur_y += dy[dir_num];
            cnt++;
            board[cur_x][cur_y] = 1;
            if (cur_x == START_POS && cur_y == START_POS) {
                answer = cnt;
            }
        }
    }

    cout << answer;
    // 여기에 코드를 작성해주세요.
    return 0;
}