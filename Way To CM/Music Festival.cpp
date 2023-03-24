// link : https://codeforces.com/contest/1801/problem/C

#include<bits/stdc++.h>
using namespace std;
typedef   double                   dd;
typedef   vector<int>              vi;
#define   endl              "\n"
#define   pb                push_back
#define   size(a)           (int)a.size()
#define   all(v)            v.begin(), v.end()
#define   rall(v)           v.rbegin(), v.rend()

const double eps = 1e-8;
const int N = 2e5 + 5;
int mod = 998244353, ii = 1;

vi tr(N, 0);
set<int> nodes;

void update(int id, int val) {
   while(id < size(tr)) {
      nodes.insert(id);
      tr[id] = max(tr[id], val);
      id += id&-id;
   }
}

int qry(int id) {
   int ans =0;
   while(id > 0) {
      nodes.insert(id);
      ans = max(ans, tr[id]);
      id -= id & -id;
   } 
   return ans;
}

void solve() {
   int n, ans = 0; cin >> n;
   vector<pair<int, vi>> vc;
   for (int i = 0; i < n; i++) {
      int mx = 0, sz; cin >> sz;
      vi vk;
      for (int j = 0; j < sz; j++) {
         int p; cin >> p;
         if(mx < max(mx, p)) vk.pb(max(mx, p));
         mx = max(mx, p);
      }
      vc.pb({mx, vk});
   }
   sort(all(vc));
   nodes.clear();
   for (int i = 0; i < n; i++) {
      int mx = vc[i].first; 
      vi v = vc[i].second;
      for (int j = 0; j < size(v); j++) {
         int ma = qry(v[j]-1);
         ans = max(ans, size(v)-j+ma);
         update(mx, size(v)-j+ma);
      }
   }
   for (int i : nodes) tr[i] = 0;
   cout << ans << endl;
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
