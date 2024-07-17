#include <iostream>
using namespace std;
//오른쪽, 아래쪽, 왼쪽, 위쪽 
enum EDir{
    E, S, W, N, DIR_CNT
};
int dx[DIR_CNT] = {0, 1, 0, -1};
int dy[DIR_CNT] = {1, 0, -1, 0};
int board[105][105];
int n, m;

bool oob(const int x, const int y) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

bool Reachable(const int x, const int y) {
    return !oob(x, y) && board[x][y] == 0;
}

void Forward(int &x, int &y, const int dir, int &num) {
    while(Reachable(x + dx[dir], y + dy[dir])) {
        x += dx[dir];
        y += dy[dir];
        board[x][y] = 65 + num;
        num = (num + 1) % 26;
    }
}

void Snail() {
    int x{ 0 };
    int y{ -1 };
    int dir{ 0 };
    int num{ 0 };
    while(1) {
        bool forwardable = false;
        for(int turning{ 0 }; turning < 4; turning++) {
            dir = (dir + 1) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (Reachable(nx, ny)) {
                forwardable = true;
                break;
            }
        }

        if (!forwardable) break;

        Forward(x, y, dir, num);
    }
}

void Print() {
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < m; j++) {
            cout << (char)board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    Snail();
    Print();
    return 0;
}