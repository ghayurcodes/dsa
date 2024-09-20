import java.util.Scanner;

public class GCDExample {
    
    // Function to return GCD of two numbers
    public static int findGCD(int num1, int num2) {
        // Base case: if the second number is 0, return the first number
        if (num2 == 0) {
            return num1;
        }
        // Recursive case: call the function with the second number and remainder of the division
        return findGCD(num2, num1 % num2);
    }

    public static void main(String[] args) {
        System.out.println("Enter 1st number.");
        Scanner in=new Scanner(System.in);
        int num1=in.nextInt();
        System.out.println("Enter 2st number.");
        int num2=in.nextInt();
    

        int[] array=new int[2];
        int gcd = findGCD(num1, num2);
        System.out.println("GCD of " + num1 + " and " + num2 + " is: " + gcd);
    }
}
