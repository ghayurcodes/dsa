import java.util.*;;

public class fibonaci_1st_day {
    public static void main(String[] args) {
        int a = 0;
        int b = 1;
        System.out.println("How many Fibonacci numbers do you want?");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println();

        for (int i = 0; i < n; i++) {
            System.out.print(a + "\t");
            int c = a + b; // Calculate next Fibonacci number
            a = b;         // Update a to the next number
            b = c;         // Update b to the next number
        }
        in.close();
    }
}
