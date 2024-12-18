    static int n, q, ar[], sp[][], L;

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    static int query(int l, int r) {
        int lg = 31 - Integer.numberOfLeadingZeros(r - l + 1);
        return gcd(sp[r][lg], sp[l + (1<<lg) - 1][lg]);
    }
    static void sparseTable() {
        for (int i = 1; i < n; i++) sp[i][0] = Math.abs(ar[i] - ar[i-1]);
        for (int bt = 1; bt <= L; bt++) {
            for (int i = 1; i < n; i++) {
                if(i - (1 << bt) + 1 < 1) {
                    continue;
                } 
                sp[i][bt] = gcd(sp[i][bt-1], sp[i-(1<<(bt-1))][bt-1]);
            }
        }
    }
