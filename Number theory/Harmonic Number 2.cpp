// problem : https://lightoj.com/problem/harmonic-number-ii

#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   int                      long long
#define   endl              "\n"

void solve() {
   int ans = 0, n, i = 1, mx = 0; cin >> n;
   if(n < 10000) {
      int ans1 = 0;
      for (int j = 1; j <= n; j++) {
         ans1 += n/j;
      }
      cout << ans1 << endl;
      return;
   }
   mx = n;
   for ( i = 1; i * i <= n; i++) {
      ans += n/i;
      mx = min(mx, n/i);
   }

   for (int j = 1; j < mx; j++) {
      ans += j * (n/j - n/(j+1));
   }
   cout << ans << endl;
}

int32_t main() {
   IO;
   int TestCase = 1, cs = 1;
   cin >> TestCase;
   while(TestCase--)
      cout << "Case " << cs++ << ": ",
      solve();
   
   return 0;
}
