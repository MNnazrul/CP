//Link : https://codeforces.com/problemset/problem/1704/D

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define size(a) (int)a.size()
int const N = 2e5 + 5;

void solve() {
   int n, m; cin >> n >> m;
   int ar[n+1][m+1];
   map<int, int> ma;
   vector<int> v;
   for (int i = 0; i < n; i++) {
      int sm = 0;
      for (int j = 0; j < m; j++) {
         cin >> ar[i][j];
         sm += ar[i][j] * (j+1);
      } 
      v.push_back(sm);
      ma[sm] = i+1;
   }
   sort(v.rbegin(), v.rend());
   cout << ma[v[0]] << ' ' << v[0]-v[1] << endl;
   
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
