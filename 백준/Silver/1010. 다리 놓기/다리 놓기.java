import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int pascal[][];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        pascal = new int[31][31];
        pascal[0][0] = 1;
        for (int i = 1; i <= 30; i++) {
            pascal[i][0] = 1;
            for (int j = 1; j <= 30; j++) {
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
        }

        int t = Integer.parseInt(br.readLine());

        for (int test = 0; test < t; test++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            System.out.println(pascal[m][n]);
        }

        br.close();
    }
}

