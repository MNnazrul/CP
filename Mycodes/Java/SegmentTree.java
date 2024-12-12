class segmentTree {
    long sm[];
    int mx[], n;
    segmentTree(int n) {
        this.n = n;
        sm = new long[4*n];
        mx = new int[4*n];
    }
    void build(int ps, int val, int cur, int left, int right) {
        if(ps < left || ps > right) return;
        if(left == right) {
            sm[cur] = val;
            mx[cur] = val;
            return;
        }
        int md = (left + right) / 2;
        build(ps, val, 2*cur, left, md);
        build(ps, val, 2*cur + 1, md + 1, right);
        mx[cur] = Math.max(mx[2*cur], mx[2*cur + 1]);
        sm[cur] = sm[2*cur] + sm[2*cur + 1];
    }
    void build(int ps, int val) {
        build(ps, val, 1, 1, n);
    }
    void update(int l, int r, int val, int cur, int left, int right) {
        if(r < left || l > right || mx[cur] < val) return;
        if(left == right) {
            sm[cur] = sm[cur] % val;
            mx[cur] = (int)sm[cur];
            return;
        }
        int md = (left + right) / 2;
        update(l, r, val, 2*cur, left, md);
        update(l, r, val, 2*cur + 1, md + 1, right);
        mx[cur] = Math.max(mx[2*cur], mx[2*cur + 1]);
        sm[cur] = sm[2*cur] + sm[2*cur + 1];
    }
    void update(int l, int r, int val) {
        update(l, r, val, 1, 1, n);
    }
    long query(int l, int r, int cur, int left, int right) {
        if(r < left || l > right) return 0L;
        if(l <= left && right <= r) {
            return sm[cur];
        }
        int md = (left + right) / 2;
        return query(l, r, 2*cur, left, md) + query(l, r, 2*cur + 1, md + 1, right);
    }
    long query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
}
