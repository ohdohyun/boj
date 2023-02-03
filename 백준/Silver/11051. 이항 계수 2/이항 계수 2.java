import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int pascal[][];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        pascal = new int[n + 1][k + 1];
        pascal[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            pascal[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % 10007;
//                System.out.println("i,j= " + i + ", " + j + " = " + pascal[i][j]);
            }
        }
        System.out.println(pascal[n][k]);


        br.close();
    }
}

