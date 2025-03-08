#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
bool visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool oob(const int x, const int y) {
    return x < 0 || y < 0 || x >= n || y >= n;
}

void init_visit() {
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            visited[i][j] = false;
        }
    }
}

bool is_unreachable(const int x, const int y) {
    return grid[x][y];
}

bool has_visited(const int x, const int y) {
    return visited[x][y];
}

int find_reachable_room_by_bfs(const int x, const int y) {
    queue<pair<int, int>> q;
    int reachable_cnt{ 1 };
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        int cur_x, cur_y;
        tie(cur_x, cur_y) = q.front();
        q.pop();
        for (int dir{ 0 }; dir < 4; dir++) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if (oob(nx, ny) || has_visited(nx, ny) || is_unreachable(nx, ny))
                continue;
            visited[nx][ny] = true;
            reachable_cnt++;
            q.push({nx, ny});
        }
    }

    return reachable_cnt;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    // Please write your code here.
    init_visit();
    int total_reachable_cnt{ 0 };
    for (int i{ 0 }; i < k; i++) {
        int x{ r[i] - 1 }, y{ c[i] - 1 };
        if (has_visited(x, y))
            continue;
        total_reachable_cnt += find_reachable_room_by_bfs(x, y);
    }
    cout << total_reachable_cnt;
    return 0;
}
