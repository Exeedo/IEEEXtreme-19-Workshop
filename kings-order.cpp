// Problem: https://csacademy.com/ieeextreme-practice/task/icarus
// Solution by: Osama Khallouf (Exeedo)

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
int group_id[N];
set<int> adj[N];
set<int> rev_adj[N];
int vis[N];

void no_sol() {
    cout << -1 << endl;
    exit(0);
}

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 1) {
            no_sol();
        }
        if (vis[v] == 0) {
            dfs(v);
        }
    }
    vis[u] = 2;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) dfs(i);
    }

    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        if (adj[i].empty()) {
            q.push({-group_id[i], -i});
        }
    }

    while(!q.empty()) {
        int u = -(q.top().second);
        q.pop();
        cout << u << " ";
        for (int v : rev_adj[u]) {
            adj[v].erase(u);
            if (adj[v].empty())
                q.push({-group_id[v], -v});
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> group_id[i];
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[b].insert(a);
        rev_adj[a].insert(b);
    }
    solve();
	return 0;
}
