import java.util.LinkedList;

public class linkedlist {
    public static void main(String[] args) {
        // Create a LinkedList
        LinkedList<String> list = new LinkedList<>();

        // Add elements to the LinkedList
        list.add("Apple");
        list.add("Banana");
        list.add("Orange");

        // Print the LinkedList
        System.out.println("LinkedList: " + list);

        // Add element at the first position
        list.addFirst("Mango");

        // Add element at the last position
        list.addLast("Grapes");

        // Print the updated LinkedList
        System.out.println("Updated LinkedList: " + list);

        // Remove the first element
        list.removeFirst();

        // Remove the last element
        list.removeLast();

        // Print the final LinkedList
        System.out.println("Final LinkedList: " + list);
    }
}
