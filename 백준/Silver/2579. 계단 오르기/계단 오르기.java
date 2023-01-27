import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Integer dp[] = new Integer[n + 1];
        Integer arr[] = new Integer[n + 1];

        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        if (n == 1) {
            System.out.println(arr[1]);
            return;
        }

        dp[0] = 0;
        dp[1] = arr[1];
        dp[2] = arr[1] + arr[2];


        for (int i = 3; i <= n; i++) {
            dp[i] = Math.max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
        }

        System.out.println(dp[n]);


        br.close();
    }
}