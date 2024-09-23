import java.util.Scanner;

public class hello {

    public static void main(String[] args) {
        System.out.println("hello");
        try (Scanner in = new Scanner(System.in)) {
            String name=in.next();
            System.out.println("your name is "+name);
        }
    

        
    }
}