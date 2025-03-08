#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int n;
int grid[25][25];
bool visited[25][25];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool out_of_boundary(const int x, const int y) {
    return x < 0 || y < 0 || x >= n || y >= n;
}

void init_visit() {
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            visited[i][j] = false;
        }
    }
}

bool is_wall(const int x, const int y) {
    return grid[x][y] == 0;
}

bool has_visited(const int x, const int y) {
    return visited[x][y];
}

int get_population_dfs(const int x, const int y) {
    visited[x][y] = true;
    int village_population{ 1 };
    for (int dir{ 0 }; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (out_of_boundary(nx, ny) || is_wall(nx, ny) || has_visited(nx, ny))
            continue;
        village_population += get_population_dfs(nx, ny);
    }
    return village_population;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    init_visit();
    priority_queue<int, vector<int>, greater<int>> village_populations;
    int total_village_num{ 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_wall(i, j) || has_visited(i, j))
                continue;
            total_village_num++;
            village_populations.push(get_population_dfs(i, j));
        }
    }
    cout << total_village_num << "\n";
    while (!village_populations.empty()) {
        cout << village_populations.top() << "\n";
        village_populations.pop();
    }

    return 0;
}
