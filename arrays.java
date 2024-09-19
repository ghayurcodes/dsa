import java.util.ArrayList;
import java.util.Scanner;

public class arrays{
    public static void main(String[] args) {
        ArrayList<Integer> numbers = new ArrayList<>();
        int[] snumbers={2,44,5,6,7,8,8};//static

        System.out.println("Do you want to use dynamic(1) or static(2)?");
        Scanner in =new Scanner(System.in);
        int opt=in.nextInt();

        if(opt==1){

        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        numbers.add(40);
        numbers.add(4,50); // numbers.set(2, 35);you can set values at custom indexes
        
        for (int i = 0; i < numbers.size(); i++) {
            System.out.println("Element at index " + i + ": " + numbers.get(i));
        }
    
       
        }

        else if(opt==2){
            for (int i = 0; i < snumbers.length; i++) {
                System.out.println("Element at index " + i + ": " + numbers.get(i));
            }
        }
        else{
            System.out.println("Please chose correct option 1 or 2!");
        
        }
        
    }
}
