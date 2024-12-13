struct FenwickTree {
    vector<int> tr;
    int sz;
    FenwickTree(int size) : sz(size) {
        tr.resize(sz + 1, 0);
    }
    void add(int ps, int val) {
        while (ps <= sz) {
            tr[ps] += val;
            tr[ps] %= mod;
            ps += ps & -ps;
        }
    }
    int query(int ps) {
        int ret = 0;
        while (ps > 0) {
            ret += tr[ps];
            ret %= mod;
            ps -= ps & -ps;
        }
        return ret;
    }
};
