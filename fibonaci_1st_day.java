import java.util.*;;

public class fibonaci_1st_day {



    static int fibonaci(int n){
        if (n <= 1) {
            return n; 
        }
        return fibonaci(n - 1) + fibonaci(n - 2);
    }




    public static void main(String[] args) {
        int a = 0;
        int b = 1;
        int c=0;
        System.out.println("How many Fibonacci numbers do you want?");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println("press 1 for normal method press 2 for recursive functon");
        int opt=in.nextInt();

        if(opt==1){
            System.out.println("0\t1\t");
            for (int i = 0; i < n; i++) {
                
                c= a + b; // Calculate next Fibonacci number
                a = b;         // Update a to the next number
                b = c;   
                System.out.print(c + "\t");      // Update b to the next number
            }

        }
        else if(opt==2){
            for (int i = 0; i < n; i++) {
                System.out.print(fibonaci(i) + "\t");
                
            }
        }

        
        in.close();
    }
}
