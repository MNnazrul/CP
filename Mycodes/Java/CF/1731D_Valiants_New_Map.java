import java.io.*;
import java.util.*;

public class Test {
    static FastReader fs;
    static PrintWriter out;

    static final int inf = 100_000_000;
    static int n, m, ar[][];

    static boolean chk(int mid) {
        boolean temp[][] = new boolean[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            Arrays.fill(temp[i], false);
            int idx = m + 1;
            for (int j = m; j >= 1; j--) {
                if(ar[i][j] < mid) idx = j;
                temp[i][j] = (idx-j >= mid ? true : false);
            }
        }
        for (int j = 1; j <= m; j++) {
            int idx = n + 1;
            for (int i = n; i >= 1; i--) {
                if(temp[i][j] == false) idx = i;
                if(idx-i >= mid) return true;                
            }
        }
        return false;
    }

    static void solve() {
        n = fs.nextInt();
        m = fs.nextInt();   
        ar = new int[n + 5][m + 5];    
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ar[i][j] = fs.nextInt();
            }
        }

        int l = 1, ans = -1, r = Math.min(n, m);
        while(l <= r) {
            int md = l + r >> 1;
            if(chk(md)) {
                ans = Math.max(ans, md);
                l = md + 1;
            } else {
                r = md - 1;
            }
        }

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
