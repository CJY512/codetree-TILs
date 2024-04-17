#include <iostream>
using namespace std;

int r, c;
char field[20][20];
int answer;

void bt(int cur_r, int cur_c, int jump_cnt) {
    char cur_color = field[cur_r][cur_c];

    if(jump_cnt == 2) {
        if(field[r-1][c-1] == cur_color) return;
        answer++;
        return;
    }

    for(int i{cur_r + 1}; i < r - 1; i++) {
        for(int j{cur_c + 1}; j < c - 1; j++) {
            if(field[i][j] == cur_color) continue;

            bt(i, j, jump_cnt + 1);
        }
    }
}

int main() {

    cin >> r >> c;
    for(int i{0};i < r; i++) {
        for(int j{0};j < c;j++) {
            cin >> field[i][j];
        }
    }

    if(field[0][0] == field[r-1][c-1]) {
        cout << "0";
        return 0;
    }

    bt(0, 0, 0);
    cout << answer;
    // 여기에 코드를 작성해주세요.
    return 0;
}