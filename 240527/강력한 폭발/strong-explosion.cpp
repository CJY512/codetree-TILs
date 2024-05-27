#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int kBOMB_TYPE = 3;
const int kCLEAR_ID = 0;
const int kBOMB_POS_ID = 1;

int n;
int board[25][25];
vector<pair<int, int>> bomb_pos;
int bomb_num;
int ans;

int boom_dx[3][4] = {
    {-2, -1, 1, 2},
    {-1, 0, 1, 0},
    {-1, -1, 1, 1}
};
int boom_dy[3][4] = {
    {0, 0, 0, 0},
    {0, 1, 0, -1},
    {-1, 1, 1, -1}
};

bool oob(const int x, const int y) {
    return x < 0 || y < 0 || x >= n || y >= n;
}

/*
 * bomb_id 은 폭탄의 고유 번호
*/
int get_bomb_trace(const int bomb_id) {
    return bomb_id + 100;
}

void boom(const int bomb_id, const int bomb_type) {
    int x, y;
    tie(x, y) = bomb_pos[bomb_id];
    int trace = get_bomb_trace(bomb_id);

    for (int i{ 0 }; i < 4; i++) {
        int nx = x + boom_dx[bomb_type][i];
        int ny = y + boom_dy[bomb_type][i];
        if (oob(nx, ny)) continue;
        if (board[nx][ny] != kCLEAR_ID) continue;
        board[nx][ny] = trace;
    }
}

void unboom(const int bomb_id, const int bomb_type) {
    int x, y;
    tie(x, y) = bomb_pos[bomb_id];
    int trace = get_bomb_trace(bomb_id);

    for (int i{ 0 }; i < 4; i++) {
        int nx = x + boom_dx[bomb_type][i];
        int ny = y + boom_dy[bomb_type][i];
        if (oob(nx, ny)) continue;
        if (board[nx][ny] != trace) continue;
        board[nx][ny] = kCLEAR_ID;
    }
}

void bt(const int bomb_id) {
    if (bomb_id == bomb_num) {
        int cnt{ 0 };
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < n; j++) {
                if (board[i][j] != 0) {
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
        return;
    }

    for (int bomb_type{ 0 }; bomb_type < kBOMB_TYPE; bomb_type++) {
        boom(bomb_id, bomb_type);
        bt(bomb_id + 1);
        unboom(bomb_id, bomb_type);
    }
}

int main() {
    cin >> n;

    for (int i{ 0 };i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == kBOMB_POS_ID) {
                bomb_pos.push_back({i, j});
                bomb_num++;
            }
        }
    }

    bt(0);

    cout << ans;
    // 여기에 코드를 작성해주세요.
    return 0;
}