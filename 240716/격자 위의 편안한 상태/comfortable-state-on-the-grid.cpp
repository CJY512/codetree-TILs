#include <iostream>
using namespace std;

int n, m;

int board[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool oob(const int x, const int y) {
    return x <= 0 || y <= 0 || x > n || y > n;
}

bool IsComfort(const int x, const int y) {
    int filled{ 0 };

    for(int dir{ 0 }; dir < 4; dir++) {
        int next_to_x = x + dx[dir];
        int next_to_y = y + dy[dir];
        if (oob(next_to_x, next_to_y)) continue;

        if (board[next_to_x][next_to_y] == 1) {
            filled++;
        }
    }

    return filled == 3;
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int r, c;
    while(m--) {
        cin >> r >> c;
        board[r][c] = 1;
        
        if (IsComfort(r, c))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}