import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // nCk
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int result = 1;

        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        for (int i = 2; i <= k; i++) {
            result /= i;
        }
        for (int i = 2; i <= n - k; i++) {
            result /= i;
        }
        System.out.println(result);

        br.close();
    }
}

