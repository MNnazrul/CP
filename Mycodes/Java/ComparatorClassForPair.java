class PairComparator implements Comparator<Pair> {
    @Override
    public int compare(Pair p1, Pair p2) {
        if(p1.x != p2.x) return Integer.compare(p1.x, p2.x);
        return Integer.compare(p1.y, p2.y);
    }
}

class Pair {
    int x, y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}


// pair class with compare class writen inside.
class Pair {
    int x, y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
    public static Comparator<Pair> byXY() {
        return (p1, p2) -> {
            if(p1.x != p2.x) return Integer.compare(p1.x, p2.x);
            return Integer.compare(p1.y, p2.y);
        }
    }
}

import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Pair> list = new ArrayList<>();
        list.add(new Pair(3, 4));
        list.add(new Pair(1, 2));
        list.add(new Pair(3, 2));
        list.add(new Pair(2, 5));

        // Use the comparator defined in Pair class
        list.sort(Pair.byXY());
        // Use the comparator class
        list.sort(new PairComparator());
        
        System.out.println("Sorted List: " + list);
    }
}
