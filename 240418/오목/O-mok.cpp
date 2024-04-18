#include <iostream>
using namespace std;

int field[20][20];
// → ↘ ↓ ↙
int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, 1, 0, -1};

int winner = 0;
int center_x = 0;
int center_y = 0;

bool isBingo(const int x, const int y, const int dir) {
    int cur_x = x;
    int cur_y = y;
    int cur_color = field[x][y];

    switch(dir) {
        case 0:
            if(y >= 15) 
                return false;
            break;
        case 1:
            if(x >= 15 || y >= 15) 
                return false;
            break;
        case 2:
            if(x >= 15) 
                return false;
            break;
        case 3:
            if(x >= 15 || y <= 3) 
                return false;
            break;
        default:
            return false;
            break;
    }

    for(int i{ 0 };i < 4; i++) {
        cur_x += dx[dir];
        cur_y += dy[dir];
        if (field[cur_x][cur_y] != cur_color) return false;
    }

    winner = cur_color;
    center_x = x + dx[dir] * 2;
    center_y = y + dy[dir] * 2;

    return true;
}

int main() {

    for(int i{ 0 };i < 19; i++) {
        for(int j{ 0 };j < 19; j++) {
            cin >> field[i][j];
        }
    }

    for(int i{ 0 };i < 19; i++) {
        for(int j{ 0 };j < 19; j++) {
            if (field[i][j]) {
                for(int dir{ 0 }; dir < 4; dir++) {
                    if(isBingo(i, j, dir)) break;
                }
            }
            if (winner) break;
        }
        if (winner) break;
    }

    cout << winner << "\n";
    if (winner) {
        cout << center_x + 1 << " " << center_y + 1;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}