#include<bits/stdc++.h>

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   int                      long long
typedef   double                   dd;
typedef   vector<int>              vi;
typedef   vector<char>             vc;
typedef   set<int>                 si;
typedef   map<int,int>             mp;
typedef   pair<int,int>            pr;
typedef   tuple<int,int, int>      tp;
typedef   vector<vector<int>>      vvi;
typedef   vector<pair<int,int>>    vpr;
#define   intmax            INT_MAX
#define   lintmax           LLONG_MAX
#define   endl              "\n"
#define   pb                push_back
#define   F                 first
#define   S                 second
#define   pi                acos(-1.0)
#define   size(a)           (int)a.size()
#define   all(v)            v.begin(), v.end()
#define   rall(v)           v.rbegin(), v.rend()
#define   bp(x)             __builtin_popcountll(x)

#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
   cerr << *it << "=" << a << " ! ";
   err(++it, args...);
}

//int ax[] = {0,  0, -1, 1, -1,  1, -1, 1};
//int ay[] = {1, -1,  0, 0, -1, -1,  1, 1};

const double eps = 1e-8;
const int N = 1e6 + 5;

int ii = 1;
int n, m; 
vector<tuple<int, int, int>> v;
vector<int> tr, mn, lazy;

void apply(int node) {
   tr[node] += lazy[node];
   if(2*node + 1 < size(tr)) {
      lazy[2*node] += lazy[node];
      lazy[2*node + 1] += lazy[node];
   }
   lazy[node] = 0;
}

void init(int node, int start, int end, int l, int r, int val) {
   apply(node);
   if(start > r || end < l) return;
   if(start >= l && end <= r) {
      lazy[node] += val;
      apply(node);
      return;
   }
   int mid = (start + end) >> 1;
   init(2 * node, start, mid, l, r, val);
   init(2 * node + 1, mid+1, end, l, r, val);
   // apply(2*node);
   // apply(2*node + 1);
   tr[node] = min(tr[2*node], tr[2*node + 1]);
}

void solve() {
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      int w, l, r;
      cin >> l >> r >> w;
      r--;
      v.push_back({w, l, r});
   }
   
   tr.assign(4*m+5, 0);
   mn.assign(4*m+5, 0);
   lazy.assign(4*m+5, 0);

   sort(all(v));
   int i1 = 0, ans = INT_MAX;

   // for (auto[w, x, y] : v) cout << x << ' ' << y << ' ' << w << endl;
   // cout << endl;

   int ww = get<0>(v[0]);
   for (int i = 0; i < n; i++) {
      auto[w, x, y] = v[i];
      // if(i == i1) init(1, 1, m, x, y, 1);
      // i1 = max(i1, i + 1);
      while(tr[1] == 0 && i1 < n) {
         auto[w1, x1, y1] = v[i1];
         init(1, 1, m-1, x1, y1, 1); 
         i1++;
         ww = w1;
      }
      // cout << i << ' ' << i1 << ' ' << ww << ' ' << w << endl;
      // cout << tr[1] << endl;
      if(tr[1] <= 0) break;
      if(tr[1] > 0) {
         ans = min(ans, ww - w);
      }
      init(1, 1, m-1, x, y, -1);
      // if(i == i1) i1++;
   }
   
   cout << ans << endl;
}

int32_t main() {
   IO;
   int TestCase = 1;

   // cin >> TestCase;
   // scanf("%d", &TestCase);
   while(TestCase--)
      solve();

   // cerr << endl << "time : "<< (float)clock()/CLOCKS_PER_SEC << " s" << endl;

   return 0;
}




/**
   stuff you should look for
   * obvious case
   * check MIN/MAX value
   * int overflow, array bounds
   * special cases (n=1?)
   * do smth instead of nothing and stay organized
   * WRITE STUFF DOWN
   * DON'T GET STUCK ON ONE APPROACH
*/
