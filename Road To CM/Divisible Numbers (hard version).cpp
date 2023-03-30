#include<bits/stdc++.h>

using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   int                      long long
typedef   double                   dd;
typedef   vector<int>              vi;
#define   endl              "\n"
#define   pb                push_back
#define   size(a)           (int)a.size()
#define   all(v)            v.begin(), v.end()
#define   rall(v)           v.rbegin(), v.rend()

int ax[] = {0,  0, -1, 1};
int ay[] = {1, -1,  0, 0};

const double eps = 1e-8;
const int N = 1e4 + 5;

int ii = 1;

int lcm(int n, int m) {
   int ans = n * m;
   ans /= __gcd(n, m);
   return ans;
}
// int mod = 998244353;


#define sz 1000009
vector <int> prime;
bitset <sz> bs;

void sieve() {
   bs.set(); // all bit = 1..
   bs[0] = bs[1] = 0;
   prime.push_back(2);
   for (int i = 3; i <= sz; i += 2) {
      if(bs[i]) {
         for (int j = i*i; j <= sz; j += i)
            bs[j] = 0;
         prime.push_back(i);
      }
   }
}

int mod = 1e9 + 7;

void solve() {
   int a, b, c, d; cin >> a >> b >> c >> d;

   int val = a * b;
   set<int> st, st1;

   for (int i = 1; i * i <= max(a, b); i++) {
      if(a % i == 0) {
         st.insert(i);
         if(i != a/i) st.insert(a/i);
      }
      if(b % i == 0) {
         st1.insert(i);
         if(i != b/i) st1.insert(b/i);
      }
   }

   for (int i : st1) {
      int kk = c/i;
      auto it = st.upper_bound(kk);
      if(it == st.begin()) continue;
      it--;
      int val = *it; int cat = val * i;
      int pp = c / cat; cat = cat * pp;
      int cc = (a * b) / __gcd(a*b, cat);
      int k = d / cc; k *= cc;
      // cerr << cat << ' ' << k << endl;
      if(k > b && k <= d and cat > a and cat <= c) {
         cout << cat << ' ' << k << endl;
         return;
      }
      //------------------
       kk = d/i;
       it = st.upper_bound(kk);
      if(it == st.begin()) continue;
      it--;
       val = *it;  cat = val * i;
       pp = d / cat; cat = cat * pp;
       cc = (a * b) / __gcd(a*b, cat);
       k = c / cc; k *= cc;
      // cerr << cat << ' ' << k << endl;
      if(k > a && k <= c and cat > b and cat <= d) {
         cout << k << ' ' << cat << endl;
         return;
      }
   } 
   cout << -1 << ' ' << -1 << endl;
}  

int32_t main() {
   IO;
   int TestCase = 1;
   sieve();
   cin >> TestCase;
   while(TestCase--)
      solve();

   // cerr << endl << "time : "<< (float)clock()/CLOCKS_PER_SEC << " s" << endl;

   return 0;
}
