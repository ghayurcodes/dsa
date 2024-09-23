import java.util.*;

public class lab1 {
    public static void main(String[] args) {

        int[][] arr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        
        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

    
        System.out.println("");
        for(int[] row : arr) {
            for(int num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }

        System.out.println("Fibonachi series");
        int a=0,b=1,c=0;
        System.out.println("Enter how many terms you wnat");
        Scanner in=new Scanner(System.in);
        int no_of_terms=in.nextInt();
        System.out.print("0 1 ");
        for(int i=0;i<no_of_terms;i++){
            c=a+b;
            a=b;
            b=c;
            
            System.out.print(c+" ");
            

        }


    }
}
