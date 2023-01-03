import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int n;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        rec(1,2);
        rec(1,3);
        rec(1,5);
        rec(1,7);

        br.close();
    }

    static void rec(int count, int num){
        if(count == n){
            if(isPrime(num)) {
                System.out.println(num);
            }
            return;
        }
        for(int i=1;i<10;i++) {
            if (i == 2 || i == 4 || i == 6 || i == 8) {
                continue;
            }
            if(isPrime(num*10 +i)){
                rec(count+1, num*10+i);
            }
        }
    }

    static boolean isPrime(int num){
        for(int i=2;i<=num/2;i++){
            if(num%i==0) {
                return false;
            }
        }
        return true;
    }
}
