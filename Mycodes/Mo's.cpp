ll cnt[1<<22]; 
int n, q;
vector<ll> a;
vector<pair<pair<int, int>, int>> qr;
ll cur = 0;
bool cmp(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2) {
   if(p1.first.first/block_size < p2.first.first/block_size) return true;
   else if(p1.first.first/block_size == p2.first.first/block_size) {
      if((p1.first.first/block_size)%2 == 0) {
         return p1.first.second < p2.first.second;
      } else return p1.first.second > p2.first.second;
   }
   return false;
}
void solve() {
   cin >> n >> q; block_size = sqrt(n);
   a.assign(n + 2, 0);
   vector<ll> ans(q);
   for (int i = 1; i <= n; i++) cin >> a[i];
   for (int i = 0; i < q; i++) {
      int l, r; cin >> l >> r;
      qr.push_back({{l, r}, i});
   }
   sort(qr.begin(), qr.end(), cmp);
   int L = 1, R = 0;
   for (auto x : qr) {
      int l = x.first.first, r = x.first.second, id = x.second;
      while(R < r) { // add
         R++;
         cur -= cnt[a[R]]*cnt[a[R]]*a[R];
         cnt[a[R]]++;
         cur += cnt[a[R]]*cnt[a[R]]*a[R];
      }
      while(R > r) {
         cur -= cnt[a[R]]*cnt[a[R]]*a[R];
         cnt[a[R]]--;
         cur += cnt[a[R]]*cnt[a[R]]*a[R];
         R--;
      } // del
      while(L > l) {
         L--;
         cur -= cnt[a[L]]*cnt[a[L]]*a[L];
         cnt[a[L]]++;
         cur += cnt[a[L]]*cnt[a[L]]*a[L];
      } // add
      while(L < l) {
         cur -= cnt[a[L]]*cnt[a[L]]*a[L];
         cnt[a[L]]--;
         cur += cnt[a[L]]*cnt[a[L]]*a[L];
         L++;
      } // del
      ans[id] = cur;
   }
   for (ll i : ans) cout << i << endl;
}