#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define size(a) (int)a.size()

int const N = 2e5 + 5;
vector<int> gr[N], a, parent, cnt;
set<pair<int, int>> st[N];
int n, m;

void pre() {
}

int unio(int node) {
   return parent[node] == node ? node : parent[node] = unio(parent[node]);
}

void solve() {
   cin >> n >> m;

   a.assign(n + 4, 0);
   parent.assign(n + 4, 0);
   cnt.assign(n + 4, 0);
   for (int i = 0; i <= n; i++) {
      gr[i].clear();
      cnt[i] = 1;
      parent[i] = i; 
      st[i].clear();
   } 

   vector<int> z;
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if(a[i] == 0) z.push_back(i);
   }
   for (int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      gr[u].push_back(v);
      gr[v].push_back(u);
      st[u].insert({a[v], v});
      st[v].insert({a[u], u});
   }
   for (int i : z) {
      int pa = unio(i);
      if(pa == i) {
         while(!st[i].empty()) {
            auto[x, y] = *st[i].begin();
            if(cnt[i] < x) break;
            st[i].erase(st[i].begin());
            int p1 = unio(y);
            if(p1 == pa) continue;
            for (auto[x1, y1] : st[p1]) {
               if(unio(y1) == pa) { continue;}
               st[i].insert({x1, y1});
            } 
            cnt[pa] += cnt[p1];
            parent[p1] = pa;
         }
      }
   }
   set<int> s1;
   for (int i = 1; i <= n; i++) s1.insert(unio(i));
   cout << (size(s1) > 1 ? "NO" : "YES") << endl;
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TestCase = 1;
   cin >> TestCase;
   while(TestCase--)
      solve();
   return 0;
}
