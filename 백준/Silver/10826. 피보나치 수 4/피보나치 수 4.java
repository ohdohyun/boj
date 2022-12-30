import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    static BigInteger dp[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        dp = new BigInteger [n+2];
        dp[0] = BigInteger.valueOf(0);
        dp[1] = BigInteger.valueOf(1);
        if(n>1) {
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1].add(dp[i-2]);
            }
        }
        System.out.println(dp[n]);

        br.close();
    }
}
