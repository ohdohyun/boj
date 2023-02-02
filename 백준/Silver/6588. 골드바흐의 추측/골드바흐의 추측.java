import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static boolean isPrime[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        isPrime = new boolean[1000001];
        Arrays.fill(isPrime, true);
        for (int i = 2; i <= 1000; i++) {
            if (isPrime[i] == true && i * i <= 1000000) {
                for (int j = i * i; j <= 1000000; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        String input;
        while (true) {
            input = br.readLine();
            int n = Integer.parseInt(input);
            if(n == 0) break;
            for (int i = 2; i <= n / 2; i++) {
                if (isPrime[i] && isPrime[n - i]) {
                    System.out.println(n + " = " + i + " + " + (n - i));
                    break;
                }
            }
        }

        br.close();
    }
}

