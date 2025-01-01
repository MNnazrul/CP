import java.io.*;
import java.util.*;

public class Test {

    static FastReader fs;
    static PrintWriter out;

    static void solve() {
        int n = fs.nextInt();
        long x = fs.nextLong(), ans = 0;
        long ar[] = new long[n + 5];
        long dp[] = new long[n + 5];
        Arrays.fill(ar, 0);
        Arrays.fill(dp, 0);
        for (int i = 1; i <= n; i++) {
            ar[i] = fs.nextLong();
            ar[i] += ar[i-1];
        }
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n, mx = n + 1;
            while(l <= r) {
                int md = l + r >> 1;
                if(ar[md] - ar[i] > x) {
                    mx = Math.min(mx, md);
                    r = md - 1;
                } else {
                    l = md + 1;
                }
            }
            if(mx <= n) {
                dp[mx] += dp[i] + 1;
            }
            ans += dp[i];
        }
        ans += dp[n];
        ans = (1L * n * (n + 1)) / 2 - ans;
        out.println(ans);
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
