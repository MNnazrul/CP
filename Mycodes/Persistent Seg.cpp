struct node {
    long long int sum;
    node *right, *left;
    node (int val) {
        sum = val;
        right = left = NULL;
    }
    node (node *l, node *r) {
        sum = l -> sum + r -> sum;
        left = l;
        right = r;
    }
};
 
vector<int> v;
int n;
 
node *build(int start = 0, int end = n-1) {
    if(start == end) 
        return new node(v[start]);
    int mid = (start + end) / 2;
    return new node(build(start, mid), build(mid+1, end));
}
 
node *update(node *cur, node *prev, int pos, int val, int start = 0, int end = n-1) {
    if(start == end) 
        return new node(val + prev->sum);
    int mid = start + end >> 1;
    return pos <= mid ? new node(update(cur->left, prev->left, pos, val, start, mid), cur->right)
            : new node(cur->left, update(cur->right, prev->right, pos, val, mid+1, end));
}
 
long long query(node *cur, int l, int r, int left = 0, int right = n-1) {
    if(left > r or right < l) 
        return 0;
    if(left >= l and right <= r)
        return cur->sum;
    int mid = left + right >> 1;
    return query(cur->left, l, r, left, mid) + query(cur->right, l, r, mid+1, right); 
} 
 
void solve() {
    cin >> n;
    v.assign(n, 0);
    for (int &i : v) cin >> i;
    vector<node> roots;
    roots.push_back(*build());
    int i1 = 1;
    int q; cin >> q;
    int cs = 1;
    while(q--) {
        int id; cin >> id;
        if(id == 1) {
            int ver, pos, val; cin >> ver >> pos >> val;
            node *n1 = update(&roots[ver], &roots[ver],pos-1, val);
            roots.push_back(*n1);
        } else {
            int ver, l, r; cin >> ver >> l >> r;
            cout << query(&roots[ver], l-1, r-1) << endl;
        }
    }
 
}
