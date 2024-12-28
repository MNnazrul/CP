import java.util.*;

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

    public static void main(String[] args) {
        // TreeSet with lambda expression to compare by x first, then by y
        TreeSet<Pair> treeSet = new TreeSet<>((p1, p2) -> {
            // Compare based on x first
            if (p1.x != p2.x) {
                return Integer.compare(p1.x, p2.x);
            }
            // If x values are the same, compare based on y
            return Integer.compare(p1.y, p2.y);
        });

        treeSet.add(new Pair(3, 5));
        treeSet.add(new Pair(1, 2));
        treeSet.add(new Pair(2, 4));
        treeSet.add(new Pair(3, 2));

        // Printing TreeSet elements
        System.out.println(treeSet); // Output: [(1, 2), (2, 4), (3, 2), (3, 5)]
    }
}
