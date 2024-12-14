    static final long inf = 1_000_000_000_000_000L;
    static int n, q, s;
    static ArrayList<Pair>[] adj;
    static boolean flg;

    static void build(int cur, int left, int right) {
        if(left == right) {
            adj[cur + n].add(new Pair(left, 0));
            adj[left].add(new Pair(cur + 5 * n, 0));
            return;
        }
        int md = (left + right) >> 1;
        int leftChild = 2 * cur, rightChild = 2 * cur + 1;
        
        build(leftChild, left, md);
        build(rightChild, md + 1, right);
     
        adj[cur + n].add(new Pair(leftChild + n, 0));
        adj[cur + n].add(new Pair(rightChild + n, 0));
        
        adj[leftChild + 5 * n].add(new Pair(cur + 5 * n, 0));
        adj[rightChild + 5 * n].add(new Pair(cur + 5 * n, 0));
    }

    static void update(int v, int l, int r, int w, int cur, int left, int right) {
        if(right < l || left > r) return;
        if(l <= left && right <= r) {
            if(flg) adj[v].add(new Pair(cur + n, w));
            else adj[cur + 5 * n].add(new Pair(v, w));
            return;
        }
        int md = left + right >> 1;
        update(v, l, r, w, 2*cur, left, md);
        update(v, l, r, w, 2*cur + 1, md + 1, right);
    }

    static void solve() {
        n = fs.nextInt();
        q = fs.nextInt();
        s = fs.nextInt();
        adj = new ArrayList[10 * n];
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
        }
        build(1, 1, n);
        while(q-- > 0) {
            int op, v, w, l, r, u;
            op = fs.nextInt();
            if(op == 1) {
                v = fs.nextInt();
                u = fs.nextInt();
                w = fs.nextInt();
                adj[v].add(new Pair(u, w));
            } else {
                flg = (op == 2);
                v = fs.nextInt();
                l = fs.nextInt();
                r = fs.nextInt();
                w = fs.nextInt();
                update(v, l, r, w, 1, 1, n);
            }
        }
        long dis[] = new long[10*n];
        Arrays.fill(dis, inf);
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(s, 0));
        dis[s] = 0;
        while(!pq.isEmpty()) {
            Edge cur = pq.poll();
            int node = cur.node; long val = cur.weight;
            for (Pair p : adj[node]) {
                int u = p.u, w = p.w;
                if(val + w < dis[u]) {
                    dis[u] = val + w;
                    pq.add(new Edge(u, dis[u]));
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            out.print((dis[i] == inf ? -1 : dis[i]) + " ");
        }
    }
    static class Edge implements Comparable<Edge> {
        int node; long weight;
        Edge(int node, long weight) {
            this.node = node;
            this.weight = weight;
        }
        @Override
        public int compareTo(Edge other) {
            return Long.compare(this.weight, other.weight);
        }
    }
    static class Pair {
        int u, w;
        Pair(int u, int w) {
            this.u = u;
            this.w = w;
        }
    }
