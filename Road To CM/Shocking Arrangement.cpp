//Link : https://codeforces.com/contest/1798/problem/D

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

// int ax[] = {0,  0, -1, 1};
// int ay[] = {1, -1,  0, 0};

const double eps = 1e-8;
const int N = 1e6 + 5, inf = 1e18;
int mod = 1e9 + 7, ii = 1;

void solve() {
   int mx = -inf, mn = inf, sm = 0, n; cin >> n;
   multiset<int> positive;
   multiset<int, greater<int>> negative;
   for (int i = 0; i < n; i++) {
      int val; cin >> val;
      mx = max(mx, val);
      mn = min(mn, val);
      if(val <= 0) negative.insert(val);
      else positive.insert(val);
   }
   if(mx-mn == sm) {
      cout << "NO" << endl;
      return;
   }
   vi a;
   for (int i = 0; i < n; i++) {
      if(!size(positive) or !size(negative)) break;
      if(sm + *positive.begin() >= mx-mn) {
         sm += *negative.begin();
         a.pb(*negative.begin());
         negative.erase(negative.begin());
      } else {
         sm += *positive.begin();
         a.pb(*positive.begin());
         positive.erase(positive.begin());
      }
   }
   while(size(positive)) 
      sm += *positive.begin(), a.pb(*positive.begin()), positive.erase(positive.begin());
   while(size(negative) and abs(sm) < mx-mn) 
      sm += *negative.begin(), a.pb(*negative.begin()), negative.erase(negative.begin());
   if(abs(sm) >= mx-mn or size(positive) or size(negative)) {
      cout << "NO" << endl;
      return;
   }
   cout << "YES" << endl;
   for (int i : a) cout << i << ' '; cout << endl;
}

int32_t main() {
   IO;
   int TestCase = 1;
   cin >> TestCase;
   while(TestCase--)
      solve();
   
   return 0;
}
