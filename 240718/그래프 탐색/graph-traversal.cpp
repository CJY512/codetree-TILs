#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[1005];
bool visited[1005];

void dfs(const int v, int &cnt) {
    for (auto w : graph[v]) {
        if (visited[w]) continue;
        visited[w] = true;
        dfs(w, ++cnt);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i{ 2 }; i <= n; i++) {
        visited[i] = false;
    }
    
    while(m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt{ 0 };
    visited[1] = true;
    dfs(1, cnt);

    cout << cnt;

    return 0;
}