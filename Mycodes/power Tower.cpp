#define endl "\n"
#define pb push_back
#define int long long
#define vi vector<int>
#define size(a) (int)a.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define bp(x) __builtin_popcountll(x)
int const N = 2e5 + 5, mod = 1e9 + 7;
 
int n, m, l, r;
vi a;
 
int MOD(int a, int b) {
    return a < b ? a : b + a%b;
}
 
int binpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
      if (b & 1)
         res = MOD(res * a, m);
      a = MOD(a * a, m);
      b >>= 1;
    }
    return res;
}
 
map<int, int> dp;
 
int phi(int val) {
    int v1 = val;
    if(dp.count(val)) return dp[val];
    int ans = val;
    for (int i = 2; i * i <= val; i++) {
        if(val % i == 0) {
            while(val%i == 0) val /= i;
            ans -= ans / i;
        }
    }
    if(val > 1) ans -= ans / val;
    return dp[v1] = ans;
}
 
int sol(int id, int po) {
    if(id == r) return a[id];
    if(po == 1) return 1;
    return binpow(a[id], sol(id+1, phi(po)), po);
}
 
void solve() {
    cin >> n >> m;
    a.assign(n + 4, 0);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    int q; cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << sol(l, m) % m << endl;
    }
}
