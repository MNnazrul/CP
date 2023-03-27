vector<int> tr;
vector<int> lazy, a;
int n;

void adjust(int node, int left, int right) {
   if(lazy[node] == 0) return;
   int val = lazy[node];
   tr[node] += (right - left + 1) * val;
   lazy[node] = 0;
   if(2*node < size(lazy)) {lazy[2*node] += val;}
   if(2*node + 1 < size(lazy)) {lazy[2*node+1] += val;}
}

void build(int node = 1, int left = 1, int right = n) {
   if(left == right) {
      tr[node] = a[left];
      return;
   }
   int mid = left + right >> 1;
   build(2*node, left, mid);
   build(2*node + 1, mid + 1, right);
   tr[node] = tr[2*node] + tr[2*node + 1];
}

void update(int node, int left, int right, int l, int r, int val) {
   adjust(node, left, right); 
   if(right < l || r < left) return;
   if(l <= left && right <= r) {
      lazy[node] += val;
      adjust(node, left, right);
      return;
   }
   int mid = (left + right) / 2;
   update(2*node, left, mid, l, r, val);
   update(2*node + 1, mid + 1, right, l, r, val);
   tr[node] = tr[node*2] + tr[node*2 + 1];
}

int qry(int node, int left, int right, int l, int r) {
   adjust(node, left, right);
   if(right < l || left > r) return 0;
   if(l <= left && right <= r) return (tr[node]);
   int mid = left + right >> 1;
   int q1 = qry(2*node, left, mid, l, r);
   int q2 = qry(2*node+1, mid+1, right, l, r);
   return q1 + q2;
}
void pre() {
   tr.assign(4*n + 5, 0);
   lazy(4*n + 5, 0);
}