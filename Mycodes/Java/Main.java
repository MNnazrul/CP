import java.io.*;
import java.util.*;

public class Main {

    static FastReader fs;
    static PrintWriter out;

    static void solve() {
        
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
    static class FastReader {
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
}

class Pair <K, V> {
    private K  key;
    private V value;
    Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }
    public K getKey() {
        return key;
    }
    public void setKey(K key) {
        this.key = key;
    }
    public V getValue() {
        return value;
    }
    public void setValue(V value) {
        this.value = value;
    }
    public static <K, V> Pair<K, V> of(K key, V value) {
        return new Pair<>(key, value);
    }
    @Override
    public String toString() {
        return "(" + key + ", " + value + ")";
    }
}
