import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int pascal[][];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        pascal = new int[201][201];
        pascal[0][0] = 1;
        for (int i = 1; i <= 200; i++) {
            pascal[i][0] = 1;
            pascal[i][i] = 1;
            for (int j = 1; j <= 200; j++) {
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
                if(pascal[i][j] > 1000000000)
                    pascal[i][j] = 1000000000;
            }
        }

//        while (true) {

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int count = n + m;
        String result = "";
        if (k > pascal[n + m][n]) {
            System.out.println(-1);
            return;
        }
        for (int i = 0; i < count; i++) {

            // k번이 n+m-1 C n-1보다 작거나 같으면 a
            // else) k번이 n+m-1 C n보다 크니까 z, k -= n+m-1 C n-1
            if (n == 0) {
                result += "z";
                m--;
            } else if (k > pascal[n + m - 1][n - 1]) {
                result += "z";
                m--;
                k -= pascal[n + m][n - 1];
            } else if (k <= pascal[n + m - 1][n - 1]) {
                result += "a";
                n--;
            }

        }
        System.out.println(result);
//        }

    }
}

