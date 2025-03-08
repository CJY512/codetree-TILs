#include <iostream>

using namespace std;

int n, m;
int from[10000], to[10000];
bool visited[1000];

void init_visit() {
    for (int i { 0 }; i < 1000; i++) {
        visited[i] = false;
    }
}

int dfs(const int node_no) {
    visited[node_no] = true;
    int total{ 1 };
    for (int i{ 0 }; i < m; i++) {
        if (from[i] == node_no && !visited[to[i]]) {
            total += dfs(to[i]);
        }
        if (to[i] == node_no && !visited[from[i]]) {
            total += dfs(from[i]);
        }
    }
    return total;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    // Write your code here!
    init_visit();
    cout << dfs(1) - 1;

    return 0;
}
