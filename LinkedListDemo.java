class Node {
    int data;
    Node next;

    
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

   
    public void reverse() {

        if(head.next==null){
            return ;
        }
        Node previous = null;
        Node current = head;
        Node next = null;

        while (current != null) {
            next = current.next;  // Save the next node
            current.next = previous;  // Reverse the link
            previous = current;  // Move the 'previous' pointer forward
            current = next;  // Move to the next node
        }
        head = previous;  // Update the head to the new first node
    }

    public void append(int data) {
        if (head == null) {
            head = new Node(data);
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new Node(data);
    }

    public void printList() {


        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public int size(){
        int size=0;
        Node temp=head;
        while(temp!=null){
            temp=temp.next;//2,3,4,5,6
            size++;//1,2,3,4,5
        }
        return size;
    }

    void remove(int index){//3 index value 4
        Node temp=head;
        int i=0;

        while(i<size()-index){//0<2   1<2
            temp=temp.next;//indexx 1  2
            i++;//i=1 i=2
        }
        temp.next=temp.next.next;//skiping teh moiddle one
    }
}


public class LinkedListDemo {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        // Adding elements to the list
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);

        System.out.println("Original List:");
        list.printList();

      
        list.reverse();

        System.out.println("Reversed List:");
        list.printList();

        System.out.println(list.size());


        list.remove(3);
        list.printList();




    }
}
