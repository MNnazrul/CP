int base = 1231LL, n;
int pwr[N];
vector<int> hashVal[N];
string str[N];
void pre() {
   pwr[0] = 1;
   for (int i = 1; i < N; i++) pwr[i] = pwr[i-1] * base % mod;
}
void hashCal() {
   for (int i = 0; i < n*n; i++) {
      if(i/n == i%n) continue;
      hashVal[i].assign(size(str[i]) + 5, 0);
      for (int j = 1; j <= size(str[i]); j++) {
         hashVal[i][j] = hashVal[i][j-1] * base % mod + (int)(str[i][j-1]-'a'+1);
         hashVal[i][j] %= mod;
         hashVal[i][j] = (hashVal[i][j] + mod) % mod;
      }
   }
}
int getHash(int id, int l, int r) {
   int len = r - l + 1;
   int ans =  hashVal[id][r] - hashVal[id][l-1] * pwr[len] % mod;
   ans %= mod; ans = (ans + mod) % mod;
   return ans;
}