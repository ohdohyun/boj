import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for(int i=1;i<=n;i++){
            for(int j=0;j<n-i;j++){
                System.out.print(" ");
            }
            for(int j=0;j<i*2-1;j++){
                System.out.print("*");
            }
            System.out.println();
            // System.out.print(n-i + "\t");
            // System.out.println(i*2 - 1);
        }

        for(int i=n-1; i>=1; i--){
            for(int j=0;j<n-i;j++){
                System.out.print(" ");
            }
            for(int j=0;j<i*2-1;j++){
                System.out.print("*");
            }
            System.out.println();
            // System.out.print(n-i + "\t");
            // System.out.println(i*2-1);
        }



    }
}
