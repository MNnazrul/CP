import java.io.*;
import java.util.*;

public class Test {

    static FastReader fs;
    static PrintWriter out;

    static void solve() {
        long n = fs.nextInt(), m = fs.nextInt();
        int k = fs.nextInt();
        TreeSet<Long> st1 = new TreeSet<>();
        TreeSet<Pair> st2 = new TreeSet<>(Pair.CMP());
        TreeSet<Pair> st3 = new TreeSet<>(Pair.CMP());
        st1.add(m);
        st2.add(new Pair(m, m));
        for (int i = 0; i < k; i++) {
            long val = fs.nextLong();
            if(i == 0 && val == m) {
                st1.clear();
                st2.clear();
                st1.add(1L);
                st1.add(n);
                st2.add(new Pair(1L, 1L));
                st2.add(new Pair(n, n));
            } else {
                st3.clear();
                for (Pair p1 : st2) {
                    long x = p1.x, y = p1.y;
                    if(val < x) {
                        st3.add(new Pair(Math.max(x - 1, 1L), y));
                        st1.add(Math.max(x - 1, 1L));
                    } else if(y < val) {
                        st3.add(new Pair(x, Math.min(y + 1, n)));
                        st1.add(Math.min(y + 1, n));
                    } else if(x <= val && val <= y) {
                        st3.add(new Pair(x, y));
                        if(!st1.contains(1L)) {
                            st3.add(new Pair(1L, 1L));
                            st1.add(1L);
                        } 
                        if(!st1.contains(n)) {
                            st3.add(new Pair(n, n));
                            st1.add(n);
                        }
                    }
                }
                st2.clear();
                for (Pair P : st3) {
                    st2.add(new Pair(P.x, P.y));
                }
            }
            out.print(st1.size() + " ");
        }
        out.println();
    }
    public static void main(String[] args) { 
        out = new PrintWriter(System.out);
        fs = null;
        if(args.length > 0) {
            try {
                fs = new FastReader(args[0]);
            } catch(IOException e) {
                e.printStackTrace();
            }
        } else {
            fs = new FastReader();
        }
        
        int T = 1;
        T = fs.nextInt();
        for (int i = 0; i < T; i++) {
            solve();
        }
        
        out.close();
    }
}

class Pair {
    long x, y;
    Pair(long x, long y) {
        this.x = x;
        this.y = y;
    }
    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
    public static Comparator<Pair> CMP() {
        return (p1, p2) -> {
            if(p1.x != p2.x) return Long.compare(p1.x, p2.x);
            return Long.compare(p1.y, p2.y);
        };
    }
}

class FastReader {
    BufferedReader br;
    StringTokenizer st;
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    public FastReader(String filePath) throws IOException {
        if (filePath != null && !filePath.isEmpty()) {
            br = new BufferedReader(new FileReader(filePath));
        } else {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
    }
    String next () {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
    int nextInt() {
        return Integer.parseInt(next());
    }
    long nextLong() {
        return Long.parseLong(next());
    }
    double nextDouble() {
        return Double.parseDouble(next());
    }
    String nextLine() {
        String str = "";
        try {
            if (st == null || !st.hasMoreTokens()) {
                str = br.readLine();
            } else {
                str = st.nextToken("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
    char nextChar() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str.charAt(0);
    }
}
