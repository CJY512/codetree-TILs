#include <iostream>
using namespace std;

int n, k;
char board[1005][1005];

enum Dir {
    N, E, S, W, DIR_COUNT
};
int dx[DIR_COUNT] = {-1, 0, 1, 0};
int dy[DIR_COUNT] = {0, 1, 0, -1};

typedef struct Laser {
    int x;
    int y;
    Dir heading; /*북동남서 0123*/
} Laser;

bool oob(const int x, const int y) {
    return x < 0 || y < 0 || x >= n || y >= n;
}

Laser GetInitPoint(const int kk) {
    Laser laser;

    int share = (kk - 1) / n;
    int remainder = (kk - 1) % n;
    
    if (share == 0) {
        laser.x = 0;
        laser.y = remainder;
        laser.heading = S;
    } else if (share == 1) {
        laser.x = remainder;
        laser.y = n - 1;
        laser.heading = W;
    } else if (share == 2) {
        laser.x = n - 1;
        laser.y = n - 1 - remainder;
        laser.heading = N;
    } else { /* share == 3 */
        laser.x = n - 1 - remainder;
        laser.y = 0;
        laser.heading = E;
    }

    return laser;
}

void Reflecting(Laser &laser) {
    char mirror = board[laser.x][laser.y];

    if (mirror == '/') {
        if (laser.heading == N) {
            laser.heading = E;
        } else if (laser.heading == E) {
            laser.heading = N;
        } else if (laser.heading == S) {
            laser.heading = W;
        } else if (laser.heading == W) {
            laser.heading = S;
        }
    }
    else if (mirror == '\\') {
        if (laser.heading == N) {
            laser.heading = W;
        } else if (laser.heading == E) {
            laser.heading = S;
        } else if (laser.heading == S) {
            laser.heading = E;
        } else if (laser.heading == W) {
            laser.heading = N;
        }
    }

    laser.x += dx[laser.heading];
    laser.y += dy[laser.heading];
}

int Simulate(Laser laser) {
    int cnt{ 0 };
    while(!oob(laser.x, laser.y)) {
        Reflecting(laser);
        cnt++;
    }

    return cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cin >> k;

    Laser laser = GetInitPoint(k);
    int answer = Simulate(laser);

    cout << answer;

    return 0;
}