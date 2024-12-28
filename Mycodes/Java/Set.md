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
