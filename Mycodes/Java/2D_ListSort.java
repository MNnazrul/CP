import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Initialize the list of lists
        List<List<Integer>> lst = new ArrayList<>();
        
        // Adding inner lists with integers
        lst.add(new ArrayList<>(Arrays.asList(3, 2, 1)));
        lst.add(new ArrayList<>(Arrays.asList(1, 2, 3)));
        lst.add(new ArrayList<>(Arrays.asList(9, 8, 7, 6)));
        lst.add(new ArrayList<>(Arrays.asList(4, 5)));
        
        // Sort the outer list lexicographically
        Collections.sort(lst, (o1, o2) -> {
            // Compare lists lexicographically (element by element)
            for (int i = 0; i < Math.min(o1.size(), o2.size()); i++) {
                int compare = Integer.compare(o1.get(i), o2.get(i));
                if (compare != 0) {
                    return compare;
                }
            }
            // If all compared elements are equal, compare based on size
            return Integer.compare(o1.size(), o2.size());
        });

        // Print the sorted list of lists
        for (List<Integer> innerList : lst) {
            System.out.println(innerList);
        }
    }
}
