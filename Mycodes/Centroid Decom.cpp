const int N = 2e5 + 5, inf = 1e18;
int mod = 1e9 + 7, ii = 1;

vector<int> gr[N], cgr[N],  cntChild, inTime, outTime, lev;
vector<int> parent, ans, lcss;
vector<vector<int>> sp;
int n, m, L, c0, anss = inf;
vector<bool> rmv;

int dfs(int node, int par ) {
   cntChild[node] = 1;
   for (int i : gr[node]) {
      if(i == par || rmv[i]) continue;
      cntChild[node] += dfs(i, node);
   }
   return cntChild[node];
}
int findCentre(int node, int par, int val) {
   for (int i : gr[node]) {
      if(i == par || rmv[i] || cntChild[i] <= val/2) continue;
      return findCentre(i, node, val);
   }
   return node;
}

void decompose(int node, int par) {
   int nd = findCentre(node, node, dfs(node, node));
   if(par != -1) cgr[par].push_back(nd),
      parent[nd] = par, cgr[nd].push_back(par);
   rmv[nd] = true;
   for (int i : gr[nd]) {
      if(rmv[i]) continue;
      decompose(i, nd);
   }
}
void pre() {
   L = log2(n) + 1;
   anss = inf;
   rmv.assign(n + 5, false);
   lcss.assign(n + 5, inf);
   cntChild.assign(n + 5, 0);
   inTime.assign(n + 5, 0);
   outTime.assign(n + 5, 0);
   lev.assign(n + 5, 0);
   ans.assign(n + 5, inf);
   parent.assign(n + 5, 0);
   sp.assign(n + 5, vector<int> (L + 4, 0));
}

void dfs2(int node = 1, int par = 1) {
   inTime[node] = ii++;
   sp[node][0] = par;
   lev[node] = lev[par] + 1;
   for (int i = 1; i <= L; i++) sp[node][i] = sp[sp[node][i-1]][i-1];

   for (int i : gr[node]) {
      if(i == par) continue;
      dfs2(i, node);
   }
   outTime[node] = ii++;
}
bool isPar(int u, int v) {
   return (inTime[u] <= inTime[v] && outTime[v] <= outTime[u]);
}
int findLCA(int u, int v) {
   if(isPar(u, v)) return u;
   if(isPar(v, u)) return v;

   for (int i = L; i >= 0; i--) {
      if(!isPar(sp[u][i], v)) u = sp[u][i];
   }
   return sp[u][0];
}
int ind = 0;
void paint(int node) {
   int lca = findLCA(ans[node], node);
   int len = lev[ans[node]] + lev[node] - 2*lev[lca];
   if(ind == 1) cout << node << ' ' << ans[node] << endl;
   ans[node] = node;
   lcss[node] = len;
   anss = min(anss, len);
   int u = parent[node];
   while(u != 0) {
      int lca = findLCA(ans[u], node);
      int len = lev[ans[u]] + lev[node] - 2*lev[lca];
      anss = min(anss, len);
      if(lcss[u] > len) {
         lcss[u] = len;
         ans[u] = node; 
      }
      u = parent[u];
   }
}
int findAns(int node) {
   int an = lcss[node];
   int u = parent[node];
   while(u != 0) {
      // int lca = findLCA(u, node);
      // int len = lev[u] + lev[node] - 2*lev[lca];
      an = min(an, lcss[u]);
      u = parent[u];
   }
   return an;
}
