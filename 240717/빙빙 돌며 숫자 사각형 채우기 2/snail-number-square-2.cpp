#include <iostream>
using namespace std;

int board[105][105];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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
        board[x][y] = num++;
    }
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
            if (Reachable(nx, ny)) {
                forwardable = true;
                break;
            }
        }

        if(forwardable) {
            Forward(x, y, dir, num);
        } else {
            break;
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