#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e9;
int n, m, x;
long long cap[55][55], o_cap[55][55];
vector<int> parent, adj[55];

int bfs() {
    parent.assign(n + 2, -1);
    queue<pair<int, long long>> q;
    q.push({1, INF});
    parent[1] = -2;
    while (!q.empty()) {
        auto[cur, flow] = q.front();
        q.pop();
        for (int v : adj[cur]) {
            if (parent[v] == -1 && cap[cur][v]) {
                parent[v] = cur;
                long long new_flow = min(flow, cap[cur][v]);
                if(v == n) {
                    return new_flow;
                }
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int FordFul() {
    int new_flow = 0, tot_flow = 0;
    while(new_flow = bfs()) {
        tot_flow += new_flow;
        int cur = n;
        while(cur != 1) {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return tot_flow;
}

bool chk(double mid) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cap[i][j] = (o_cap[i][j] / mid);
        }
    }
    return FordFul() >= x;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(10);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int u, v, c; 
        cin >> u >> v >> c;
        adj[u].push_back(v);
        o_cap[u][v] = c;
    }

    FordFul();

    double l = 0.0, r = 10000000.0, ans = 0.0;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if(chk(mid)) {
            ans = max(ans, mid);
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << ans*x << "\n";

    return 0;
}