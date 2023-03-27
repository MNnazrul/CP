vector<vi> matMul(vector<vi> v1, vector<vi> v2) {
   int ROW = size(v1);
   vector<vi> ans(ROW, vi(ROW, 0));
   for (int i = 0; i < ROW; i++)
   for (int j = 0; j < ROW; j++) {
      int val = 0;
      for (int k = 0; k < ROW; k++) {
         val = val + v1[i][k] * v2[k][j] % mod;
         val %= mod;
      }
      ans[i][j] = val;
   }
   return ans;
}

vector<vi> POWER(vector<vi> v, int p) {
   vector<vi> ans(size(v), vi(size(v), 0));
   for (int i = 0; i < size(v); i++) ans[i][i] = 1; // identity mat.
   while(p > 0) {
      if(p&1) ans = matMul(v, ans);
      v = matMul(v, v);
      p /= 2;
   }
   return ans;
}