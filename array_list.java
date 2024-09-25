import java.util.ArrayList;


public class array_list {
    public static void main(String[] args) {
        ArrayList<Integer> list=new ArrayList<Integer>();
        System.out.println(list);
     list.add(34);
     list.add(31);
     list.add(88);

     System.out.println(list.get(2));
     list.add(2,34);
     System.out.println(list.get(2));
     System.out.println(list.get(3));

    //  list.set(index, element) used to replace 
     
     



    }
}
