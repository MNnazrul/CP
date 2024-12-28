# Hashset.

HashSet in Java
The HashSet class in Java is part of the java.util package and implements the Set interface. It is backed by a HashMap and is designed to store unique elements with high performance for basic operations.

* Key Features:
  - Stores Unique Elements Only:
    - Duplicate elements are not allowed.
  - Unordered:
    - The order of elements is not maintained; it depends on the hash function.
  - Allows Null:
    - A single null element can be stored.
  - Fast Operations:
    - Average time complexity of O(1) for insertion, deletion, and lookup.
    
* How It Works Internally:
  - Hashing:
    - When you add an element, HashSet computes the hash code of the element.
    - The hash code determines the bucket where the element is stored.
  - Collision Handling:
    - If multiple elements have the same hash code, they are stored in the same bucket as a linked list (or tree structure in Java 8+ for performance).
  - Equality Check:
    - Before adding an element, HashSet checks if an equivalent element (using equals() method) already exists in the set.

## Common Methods in HashSet

* add(E e):
    - Adds the specified element to the set.
    - Returns true if the element was added successfully (i.e., it was not already present).
    ```java
    HashSet<Integer> set = new HashSet<>();
    set.add(1); // true
    set.add(1); // false (duplicate)
    ```
    
* contains(Object o):
    - Checks if the set contains the specified element.
    - Returns true if the element is found.
    ``` java
    Copy code
    set.contains(1); // true
    ```

* remove(Object o):
  - Removes the specified element from the set if it is present.
  - Returns true if the element was removed.
  ``` java
  set.remove(1); // true
  ```

* size():
  - Returns the number of elements in the set.
  ```java
  set.size(); // 0
  ```

* isEmpty():
  - Checks if the set is empty.
  - Returns true if the set has no elements.
  ```java
  set.isEmpty(); // true  
  ```

* clear():
  - Removes all elements from the set.
  ```java
  Copy code
  set.clear();
  ```

* iterator():
  - Returns an iterator for traversing the set.
  ```java
  Copy code
  for (int value : set) {
      System.out.println(value);
  }
  ```


| **Method**               | **Time Complexity (Average Case)** | **Time Complexity (Worst Case)** | **Explanation**                                                                 |
|--------------------------|-----------------------------------|-----------------------------------|---------------------------------------------------------------------------------|
| **`add(E e)`**           | `O(1)`                          | `O(n)`                          | Adding relies on hashing. Worst case due to hash collisions.                   |
| **`contains(Object o)`** | `O(1)`                          | `O(n)`                          | Membership check is fast; worst case with hash collisions.                     |
| **`remove(Object o)`**   | `O(1)`                          | `O(n)`                          | Removal uses hashing. Worst case occurs with many collisions.                  |
| **`size()`**             | `O(1)`                          | `O(1)`                          | Retrieves the size from an internal variable.                                  |
| **`isEmpty()`**          | `O(1)`                          | `O(1)`                          | Checks if the size is `0`.                                                     |
| **`clear()`**            | `O(n)`                          | `O(n)`                          | Removes all elements, requiring traversal of the set.                          |
| **`iterator()`**         | `O(n)`                          | `O(n)`                          | Iteration visits all elements in the set.                                      |







### **TreeSet in Java**

`TreeSet` is a NavigableSet implementation in Java that is part of the `java.util` package. It is based on **Red-Black Tree** (a balanced binary search tree) and stores elements in **sorted order**. 

### **Key Characteristics:**
- **Sorted Order**: Elements are stored in ascending order by default, but a custom comparator can be used.
- **No Duplicates**: Ensures that only unique elements are stored.
- **NavigableSet**: Implements the `NavigableSet` interface, providing methods to navigate through the set.
- **Thread-Safety**: It is **not thread-safe**, but external synchronization can be used if needed.
  
---

### **TreeSet Methods and Time Complexity**

| **Method**                | **Description**                                                                 | **Time Complexity**    |
|---------------------------|---------------------------------------------------------------------------------|------------------------|
| `add(E e)`                | Adds the specified element to the set if it is not already present.             | \( O(\log n) \)        |
| `remove(Object o)`        | Removes the specified element from the set.                                     | \( O(\log n) \)        |
| `contains(Object o)`      | Returns `true` if the set contains the specified element.                       | \( O(\log n) \)        |
| `isEmpty()`               | Returns `true` if the set is empty.                                             | \( O(1) \)             |
| `size()`                  | Returns the number of elements in the set.                                      | \( O(1) \)             |
| `clear()`                 | Removes all the elements from the set.                                          | \( O(n) \)             |
| `first()`                 | Returns the first (lowest) element in the set.                                  | \( O(1) \)             |
| `last()`                  | Returns the last (highest) element in the set.                                  | \( O(1) \)             |
| `ceiling(E e)`            | Returns the least element greater than or equal to `e`.                         | \( O(\log n) \)        |
| `floor(E e)`              | Returns the greatest element less than or equal to `e`.                         | \( O(\log n) \)        |
| `higher(E e)`             | Returns the least element strictly greater than `e`.                            | \( O(\log n) \)        |
| `lower(E e)`              | Returns the greatest element strictly less than `e`.                            | \( O(\log n) \)        |
| `pollFirst()`             | Retrieves and removes the first (lowest) element in the set.                    | \( O(\log n) \)        |
| `pollLast()`              | Retrieves and removes the last (highest) element in the set.                    | \( O(\log n) \)        |
| `descendingIterator()`    | Returns an iterator over the elements in the set in descending order.          | \( O(n) \)             |
| `subSet(E fromElement, E toElement)` | Returns a view of the portion of the set between the specified range.      | \( O(\log n) \)        |
| `headSet(E toElement)`    | Returns a view of the set with elements strictly less than `toElement`.         | \( O(\log n) \)        |
| `tailSet(E fromElement)`  | Returns a view of the set with elements greater than or equal to `fromElement`. | \( O(\log n) \)        |
| `comparator()`            | Returns the comparator used for sorting elements, or `null` if natural ordering. | \( O(1) \)             |

---

### **Operations Available in TreeSet**

#### **1. `ceiling(E e)`**:
- Returns the least element greater than or equal to `e`.
- **Time Complexity**: \( O(\log n) \)

#### **2. `floor(E e)`**:
- Returns the greatest element less than or equal to `e`.
- **Time Complexity**: \( O(\log n) \)

#### **3. `higher(E e)`**:
- Returns the least element strictly greater than `e`.
- **Time Complexity**: \( O(\log n) \)

#### **4. `lower(E e)`**:
- Returns the greatest element strictly less than `e`.
- **Time Complexity**: \( O(\log n) \)

#### **5. `pollFirst()`**:
- Retrieves and removes the first (lowest) element.
- **Time Complexity**: \( O(\log n) \)

#### **6. `pollLast()`**:
- Retrieves and removes the last (highest) element.
- **Time Complexity**: \( O(\log n) \)

#### **7. `subSet(E fromElement, E toElement)`**:
- Returns a view of the set between the range `fromElement` and `toElement`.
- **Time Complexity**: \( O(\log n) \)

#### **8. `headSet(E toElement)`**:
- Returns a view of the set with elements strictly less than `toElement`.
- **Time Complexity**: \( O(\log n) \)

#### **9. `tailSet(E fromElement)`**:
- Returns a view of the set with elements greater than or equal to `fromElement`.
- **Time Complexity**: \( O(\log n) \)

---

### **Example Usage**

```java
import java.util.*;

public class TreeSetExample {
    public static void main(String[] args) {
        TreeSet<Integer> treeSet = new TreeSet<>();
        
        // Adding elements
        treeSet.add(10);
        treeSet.add(20);
        treeSet.add(30);
        treeSet.add(5);

        // Ceiling and Floor
        System.out.println("Ceiling of 15: " + treeSet.ceiling(15));  // Output: 20
        System.out.println("Floor of 25: " + treeSet.floor(25));      // Output: 20

        // Higher and Lower
        System.out.println("Higher than 20: " + treeSet.higher(20));  // Output: 30
        System.out.println("Lower than 20: " + treeSet.lower(20));    // Output: 10

        // Polling First and Last
        System.out.println("First element: " + treeSet.pollFirst());  // Output: 5
        System.out.println("Last element: " + treeSet.pollLast());    // Output: 30

        // SubSet and TailSet
        SortedSet<Integer> subSet = treeSet.subSet(10, 30);
        System.out.println("SubSet: " + subSet);  // Output: [10, 20]

        SortedSet<Integer> tailSet = treeSet.tailSet(10);
        System.out.println("TailSet: " + tailSet);  // Output: [10, 20]
    }
}
```
