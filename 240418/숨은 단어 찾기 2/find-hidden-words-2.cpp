#include <iostream>
using namespace std;

#define MAX_DIR 8

int n, m;
char board[55][55];
// ← ↙ ↓ ↘ → ↗ ↑ ↖
int dx[MAX_DIR] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[MAX_DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool oob(const int x, const int y) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

int count_LEE(const int x, const int y) {
    int sum = 0;
    for(int dir{ 0 }; dir < MAX_DIR; dir++) {
        if (oob(x + dx[dir] * 2, y + dy[dir] * 2)) continue;
        if (board[x + dx[dir]][y + dy[dir]] == 'E' &&
        board[x + dx[dir] * 2][y + dy[dir] * 2] == 'E') {
            sum++;
        }
    }

    return sum;
}

int main() {

    cin >> n >> m;
    for(int i{ 0 }; i < n; i++) {
        string s;
        cin >> s;
        for(int j{ 0 }; j < m; j++) {
            board[i][j] = s[j];
        }
    }

    int cnt = 0;

    for(int i{ 0 }; i < n; i++) {
        for(int j{ 0 }; j < m; j++) {
            if (board[i][j] == 'L') 
                cnt += count_LEE(i, j);
        }
    }

    cout << cnt;

    // 여기에 코드를 작성해주세요.
    return 0;
}