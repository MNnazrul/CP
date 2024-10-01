int const N = 1e5 + 5;
vector<int> tr[4*N], ar[N];
int sz;
int pos[N], parent[N], depth[N], heavy[N], top[N]; 
vector<int> adj[N], seq;
void fun(vector<int> &st1, vector<int> &st2) {
    for (auto I : st2) {
        st1.push_back(I);
    }
    sort(st1.begin(), st1.end());
    while(st1.size() > 10) {
        st1.pop_back();
    }
}

void build(int nd, int b, int e) {
    if(b == e) {
        tr[nd] = ar[b];
        return;
    }
    int md = b + e >> 1;
    build(2*nd, b, md);
    build(2*nd + 1, md+1, e);
    fun(tr[nd], tr[2*nd]);
    fun(tr[nd], tr[2*nd+1]);
}
 
void query( vector<int>& ans, int l, int r, int u = 1, int st = 1, int en = sz) {
    if (r<st || en<l)  return ;
    if (l<=st && en<=r) {
        fun(ans, tr[u]);
        return;
    }
    int mid = (st+en)/2;
    query(ans, l, r, 2*u, st, mid); 
    query(ans, l, r, 2*u+1, mid+1, en);
}

int go(int cur, int par) {
    parent[cur] = par;
    int C = 0, children = 1, mx = 0;
    for (int i : adj[cur]) {
        if(i == par) continue;
        depth[i] = depth[cur] + 1;
        C = go(i, cur);
        children += C;
        if(C > mx) {
            heavy[cur] = i;
            mx = C;
        }
    }
    return children;
}

void go2(int cur, int tp) {
    seq.push_back(cur);
    top[cur] = tp;
    pos[cur] = seq.size();
    if(heavy[cur] > 0) {
        go2(heavy[cur], tp);
        for (int i : adj[cur]) {
            if(i == parent[cur] || heavy[cur] == i) 
                continue;
            go2(i, i);
        }
    }
}

void find(int u, int v, vector<int>&ans) {
    int x = top[u], y = top[v];
    if(x == y) {
        int l = pos[u], r = pos[v];
        if(l > r) swap(l, r);
        query(ans, l, r);
        return;   
    }
    if(depth[x] > depth[y]) {
        int l = pos[x], r = pos[u];
        if(l > r) swap(l, r);
        query(ans, l, r);
        u = parent[x];
    } else {
        int l = pos[y], r = pos[v];
        if(l > r) swap(l, r);
        query(ans, l, r);
        v = parent[y];
    }
    find(u, v, ans);
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ap;
    for (int i = 1; i <= m; i++) {
        int c; cin >> c;
        ap.push_back(c);
    }
    int c1 = go(1, 1);
    go2(1, 1);
    for (int i = 0; i < m; i++) {
        ar[pos[ap[i]]].push_back(i+1);
    }
    for (int i = 1; i <= n; i++) {
        sort(ar[i].begin(), ar[i].end());
        while(ar[i].size() > 10) {
            ar[i].pop_back();
        }
    }
    sz = n;
    build(1, 1, n);
    while(q--) {
        int u, v, a;
        cin >> u >> v >> a;
        vector<int> ans;
        find(u, v, ans);
        cout << min(a, (int)ans.size()) << " ";
        for (int i = 0; i < min(a,(int)ans.size()); i++) {
            cout << ans[i] << " ";
        } cout << endl;
    }
}