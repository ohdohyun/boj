import java.io.*;
import java.util.*;
public class Main {
    public static int a[], b[];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        a = new int[2000001];
        int count=0;
        for(int i=2; i<=2000000; i++) {
            if(a[i] == 1) continue;
            count++;
            for(int j=i*2; j<=2000000; j+=i) {
                a[j] =1;
            }
        }
        b = new int[count];
        count=0;
        for(int i=2000000; i>=2; i--) {
            if(a[i] ==0) {
                b[count++] = i;
            }
        }
        boolean check;
        for(int k=0; k<N; k++) {
            check=false;
            long x = sc.nextLong();
            long y = sc.nextLong();
            x +=y;
            if(x ==2 || x== 3) {
                System.out.println("NO");
            }else if(x %2 ==0 || x==5) {
                System.out.println("YES");
            }else {
                x -=2;

                for(long i=b.length-1; i>=0; i--) {
                    if(x<= b[(int)i]) {
                        check=true;
                        break;
                    }
                    if(x%b[(int) i]==0) {
                        System.out.println("NO");
                        break;
                    }
                    if (i == 0) {
                        System.out.println("YES");
                    }
                }
                if(check==true) {
                    System.out.println("YES");
                }
            }
        }
    }
}
