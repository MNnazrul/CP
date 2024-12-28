// I don't know if it will work or not.

import java.util.*;

public class OrderedSet<T extends Comparable<T>> {
    private final TreeMap<T, Integer> coordinateMap = new TreeMap<>(); // Value -> Compressed Index
    private final ArrayList<T> reverseMap = new ArrayList<>();         // Compressed Index -> Value
    private int[] fenwickTree;                                         // Fenwick Tree
    private int size;

    // Constructor to initialize the Fenwick Tree
    public OrderedSet() {
        this.size = 0;
    }

    // Add an element
    public void add(T element) {
        compress(element);
        int idx = coordinateMap.get(element);
        if (query(idx, idx) == 0) { // Avoid duplicate updates
            update(idx, 1);
            size++;
        }
    }

    // Remove an element
    public void remove(T element) {
        if (coordinateMap.containsKey(element)) {
            int idx = coordinateMap.get(element);
            if (query(idx, idx) > 0) { // Only if it exists
                update(idx, -1);
                size--;
            }
        }
    }

    // Find the number of elements strictly smaller than x (order_of_key)
    public int orderOfKey(T x) {
        if (!coordinateMap.containsKey(x)) {
            compress(x); // If not present, temporarily map x
        }
        int idx = coordinateMap.get(x);
        return prefixSum(idx - 1); // Sum of all counts < idx
    }

    // Find the k-th smallest element (find_by_order)
    public T findByOrder(int k) {
        if (k >= size) return null; // Out of bounds
        int low = 1, high = fenwickTree.length - 1, resultIdx = -1;

        // Binary search for the smallest index where prefixSum >= k + 1
        while (low <= high) {
            int mid = (low + high) / 2;
            if (prefixSum(mid) > k) {
                resultIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return reverseMap.get(resultIdx - 1); // Reverse mapping to original value
    }

    // Private helper to update Fenwick Tree
    private void update(int idx, int delta) {
        while (idx < fenwickTree.length) {
            fenwickTree[idx] += delta;
            idx += idx & -idx;
        }
    }

    // Prefix sum query for Fenwick Tree
    private int prefixSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += fenwickTree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    // Query range sum [l, r]
    private int query(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }

    // Coordinate compression
    private void compress(T element) {
        if (!coordinateMap.containsKey(element)) {
            reverseMap.add(element);
            coordinateMap.put(element, reverseMap.size());
        }
        if (fenwickTree == null || fenwickTree.length <= reverseMap.size()) {
            fenwickTree = new int[reverseMap.size() + 1];
        }
    }
}
