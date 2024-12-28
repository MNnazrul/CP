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
  Copy code
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
