import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static boolean isPrime[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        isPrime = new boolean[n + 2];

        for (int i = 2; i <= n; i++) {
            if (isPrime[i] == false) {
                k--;
                if (k == 0) {
                    System.out.println(i);
                    return;
                }
                for (int j = i * i; j <= n; j += i) {
                    if (isPrime[j] == false) {
                        k--;
                        isPrime[j] = true;
                    }

                    if (k == 0) {
                        System.out.println(j);
                        return;
                    }
                }
            }

        }

        br.close();
    }
}

