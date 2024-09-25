import java.util.*;


public class arays {
    public static void main(String[] args) {
        // int arr[]=new int[3];
        // int[][] ary=new int[2][3];
        // arr[2]=99;
        // arr[0]=9;
       
        
        // for(int i=0;i<arr.length;i++){
        //     System.out.println(arr[i]);
        // }

        String first="ghayur";//string in java are immutable
        String last="ahayur";
        // System.out.println(first.substring(3, 6));
        //just use string builder for more efficent code
        StringBuilder s=new StringBuilder("hello");
        System.out.println(s);
        

        // for(int i=0;i<s.length()/2;i++){
        //   int front=i;
        //   int back=s.length()-1-i;

        //   char atfront=s.charAt(front);         //reverse a string
        //   char atback=s.charAt(back);

        //   s.setCharAt(front, atback);
        //   s.setCharAt(back, atfront);
        // }
        // System.err.println();

        // StringBuilder se=new StringBuilder();
        // for (int i = 0; i < s.length(); i++) {
        //     se.append(s.charAt(s.length()-1-i));          //own method
        // }
        // System.out.println(se);
        

    }
}
