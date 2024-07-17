#include <iostream>
using namespace std;

int board[105][105];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool oob(const int x, const int y) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

void Snail() {
    int x{ -1 };
    int y{ 0 };
    int dir{ 3 };
    int num{ 1 };
    while(1) {
        bool forwardable = false;
        for(int dir_add{ 0 }; dir_add < 4; dir_add++) {
            dir = (dir + 1) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (oob(nx, ny) || board[nx][ny] != 0) continue;

            cout << "forwardable\ndir="<<dir<<"\n";
            forwardable = true;
            break;
        }

        if(!forwardable) break;

        while(!oob(x + dx[dir], y + dy[dir]) && board[x + dx[dir]][y + dy[dir]] == 0) {
            x += dx[dir];
            y += dy[dir];
            board[x][y] = num++;
        }
    }
}

void Print() {
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < m; j++) {
            cout << board[i][j] << " ";
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