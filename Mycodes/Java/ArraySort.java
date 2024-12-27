import java.util.*;

// sort arrays and list 


public class Test {
    static List<Integer> lt;
    public static void main(String[] args) {

        // -------------------- sorting array-----------------
        Student[] students = {
            new Student(1, "Alice"),
            new Student(1, "Alice"),
            new Student(2, "Bob"),
            new Student(1, "Charlie"),
            new Student(2, "Zoe")
        };

        // System.out.println(students[0]);

        // Arrays.fill(students, new Students(0, "NUILL"));


        // --------------- this is for roll in increasing order but name in decreasing order.
        // Arrays.sort(students, Comparator.comparing(Student::getRoll)
        //     .thenComparing(Student::getName, Comparator.reverseOrder()));
        
        // ---------------This is for full reversed--------run the code for better understading. 

        // Arrays.sort(students, Comparator.comparing(Student::getRoll).thenComparing(Student::getName).reversed());

        // ----------------- sort using lambda expression - roll in asscending order name in descending order ---------------
        
        Arrays.sort(students, (o1, o2) -> {
            if(o1.roll != o2.roll) {
                return Integer.compare(o1.roll, o2.roll);
            }
            return o2.name.compareTo(o1.name);
        });

        // for (Student s : students) {
        //     System.out.println(s);
        // }


        /**
         sorting list.
        */

        List <Student> list = new ArrayList<>();
        list.add(new Student(2, "Alice"));
        list.add(new Student(1, "Bob"));
        list.add(new Student(2, "Charlie"));
        list.add(new Student(1, "David"));

        // ------------- roll in asscending order name in descending order. 

        // list.sort((o1, o2) -> {
        //     if(o1.roll != o2.roll) {
        //         return Integer.compare(o1.roll, o2.roll);
        //     }
        //     return o2.name.compareTo(o1.name);
        // });

        // 
        // list.sort(Comparator.comparing(Student::getRoll).thenComparing(Student::getName, Comparator.reverseOrder()));

        // System.out.println(list);
        
        
        
        // double a = 1.0/3.0;
        // double b = 0.3333333333333333333333333;
        // int result = Double.compare(a, b);
        // System.out.println(result + " " + a);
    }
}

class Student {
    int roll;
    String name;
    Student(int roll, String name) {
        this.roll = roll;
        this.name = name;
    }
    @Override
    public String toString() {
        return roll + " " + name;
    }
    public String getName() {
        return name;
    }
    public int getRoll() {
        return roll;
    }
}

/*

1 David
1 Bob
2 Charlie
2 Alice

0.3333333333333333

 */
