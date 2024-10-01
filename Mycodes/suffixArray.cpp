void count_sort(vector<int> &p, vector<int> &c) {
   int n = size(p);
   vector<int> cnt(n);
   for (auto x: c) {
      cnt[x]++;
   }
   vector<int> p_new(n);
   vector<int> pos(n);
   pos[0] = 0;
   for (int i = 1; i < n; ++i) {
      pos[i] = pos[i - 1] + cnt[i - 1];
   }
   for (auto x: p) {
      int i = c[x];
      p_new[pos[i]] = x;
      pos[i]++;
   }
   p = p_new;
}
vector<int> findSA(string s) {
   int n = size(s);
   vector<int> p(n), c(n);
   {
     //k = 0
      vector<pair<char, int>> a(n);
      for (int i = 0; i < n; ++i) a[i] = {s[i], i};
      sort(a.begin(), a.end());
  
      for (int i = 0; i < n; ++i) p[i] = a[i].second;
      c[p[0]] = 0;
      for (int i = 1; i < n; ++i) {
         if (a[i].first == a[i - 1].first) {
         c[p[i]] = c[p[i - 1]];
         } else {
            c[p[i]] = c[p[i - 1]] + 1;
         }
      }
   }
   int k = 0;
   while ((1 << k) < n) {
    // k -> k + 1
      for (int i = 0; i < n; ++i) {
         p[i] = (p[i] - (1 << k) + n) % n;
      }
      count_sort(p, c);
      vector<int> c_new(n);
      c_new[p[0]] = 0;
      for (int i = 1; i < n; ++i) {
         pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
         pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
         if (now == prev) {
            c_new[p[i]] = c_new[p[i - 1]];
         } else {
            c_new[p[i]] = c_new[p[i - 1]] + 1;
         }
      }
      c = c_new;
      k++;
   }
   return p;
}
void solve() {
   string s; cin >> s;
   // long long ck; cin >> ck;
   s = s + "$";
   int n = size(s);
   vector<int> p(n), c(n);
   {
     //k = 0
      vector<pair<char, int>> a(n);
      for (int i = 0; i < n; ++i) a[i] = {s[i], i};
      sort(a.begin(), a.end());
  
      for (int i = 0; i < n; ++i) p[i] = a[i].second;
      c[p[0]] = 0;
      for (int i = 1; i < n; ++i) {
         if (a[i].first == a[i - 1].first) {
         c[p[i]] = c[p[i - 1]];
         } else {
            c[p[i]] = c[p[i - 1]] + 1;
         }
      }
   }
   int k = 0;
   while ((1 << k) < n) {
    // k -> k + 1
      for (int i = 0; i < n; ++i) {
         p[i] = (p[i] - (1 << k) + n) % n;
      }
      count_sort(p, c);
      vector<int> c_new(n);
      c_new[p[0]] = 0;
      for (int i = 1; i < n; ++i) {
         pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
         pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
         if (now == prev) {
            c_new[p[i]] = c_new[p[i - 1]];
         } else {
            c_new[p[i]] = c_new[p[i - 1]] + 1;
         }
      }
      c = c_new;
      k++;
   }
   // for (int i : p) cout << i << ' '; cout << endl;
  
   // finding lcp..
   vi lcp(n-1);
   k = 0;
   for (int i = 0; i < n-1; i++) {
      int ps = c[i];
      int j = p[ps-1];
      while(s[i+k] == s[j+k]) k++;
      lcp[ps-1] = k;
      k = max(k-1, 0);
   }
   // for (int i : lcp) cout << i << ' '; cout << endl;
 
   // for (int i = 0; i < n; i++) {
   //    cout << p[i] << ' ' << s.substr(p[i]) << endl;
   // } cout << endl;
 
 
 
   vector<int> pre(n + 5, 0);
   for (int i = 1; i < n; i++) {
      int lc = lcp[i-1];
      // cout << lcp[i-1] << ' ' << n-p[i] << endl;
      pre[lcp[i-1]+1]++;
      pre[n-p[i]]--;
   }
   for (int i = 1; i <= n; i++) pre[i] += pre[i-1];
   for (int i = 1; i < n; i++) cout << pre[i] << ' ';
   // string ans;
   // for (int i = 1; i < n; i++) {
   //    long long pp = n - p[i] - 1 - lcp[i-1];
   //    if(pp >= ck) {
   //       ans = s.substr(p[i], ck + lcp[i-1]);
   //       break;
   //    }
   //    ck -= pp;
   // }
   // cout << ans << endl;
}
 
int32_t main() {
   IO;
   int TestCase = 1;
   // cin >> TestCase;
   while(TestCase--)
      solve();
   
   return 0;
}
