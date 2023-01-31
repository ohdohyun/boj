import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static StringTokenizer st;
    static int map[][];
    static int maxDp[][];
    static int minDp[][];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        map = new int[n][3];
        maxDp = new int[n][3];
        minDp = new int[n][3];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < 3; i++) {
            maxDp[0][i] = map[0][i];
            minDp[0][i] = map[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {

                switch (j) {
                    case 0:
                        maxDp[i][j] = Math.max(maxDp[i - 1][0], maxDp[i - 1][1]);
                        maxDp[i][j] += map[i][j];
                        minDp[i][j] = Math.min(minDp[i - 1][0], minDp[i - 1][1]);
                        minDp[i][j] += map[i][j];
                        break;
                    case 1:
                        maxDp[i][j] = Math.max(maxDp[i - 1][0], Math.max(maxDp[i - 1][1], maxDp[i - 1][2]));
                        maxDp[i][j] += map[i][j];
                        minDp[i][j] = Math.min(minDp[i - 1][0], Math.min(minDp[i - 1][1], minDp[i - 1][2]));
                        minDp[i][j] += map[i][j];
                        break;
                    case 2:
                        maxDp[i][j] = Math.max(maxDp[i - 1][1], maxDp[i - 1][2]);
                        maxDp[i][j] += map[i][j];
                        minDp[i][j] = Math.min(minDp[i - 1][1], minDp[i - 1][2]);
                        minDp[i][j] += map[i][j];
                        break;
                }
            }
        }

        System.out.print(Math.max(maxDp[n - 1][0], Math.max(maxDp[n - 1][1], maxDp[n - 1][2])) + " ");
        System.out.println(Math.min(minDp[n - 1][0], Math.min(minDp[n - 1][1], minDp[n - 1][2])));


        br.close();
    }
}

