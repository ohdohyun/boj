import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static StringTokenizer st;
    static int maxDp[][];
    static int minDp[][];
    static int input[];

    /*static void printMap() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(maxDp[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();

    }*/

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        maxDp = new int[2][3];
        minDp = new int[2][3];
        input = new int[3];

        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < 3; j++) {
            input[j] = minDp[1][j] = maxDp[1][j] = minDp[0][j] = maxDp[0][j] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < 3; j++) {
                maxDp[0][j] = maxDp[1][j];
                minDp[0][j] = minDp[1][j];
            }
            for (int j = 0; j < 3; j++) {
                input[j] = Integer.parseInt(st.nextToken());
            }

            for (int j = 0; j < 3; j++) {
                switch (j) {
                    case 0:
                        maxDp[1][0] = Math.max(maxDp[0][0], maxDp[0][1]) + input[0];
                        minDp[1][0] = Math.min(minDp[0][0], minDp[0][1]) + input[0];
                        break;
                    case 1:
                        maxDp[1][1] = Math.max(maxDp[0][0], Math.max(maxDp[0][1], maxDp[0][2])) + input[1];
                        minDp[1][1] = Math.min(minDp[0][0], Math.min(minDp[0][1], minDp[0][2])) + input[1];
                        break;
                    case 2:
                        maxDp[1][2] = Math.max(maxDp[0][1], maxDp[0][2]) + input[2];
                        minDp[1][2] = Math.min(minDp[0][1], minDp[0][2]) + input[2];
                        break;
                }
            }

            /*System.out.println("input[" + 0 + "] = " + input[0] + ", input[" + 1 + "] = " + input[1] + ", input[" + 2 + "] = " + input[2]);
            printMap();*/
        }

        System.out.print(Math.max(maxDp[1][0], Math.max(maxDp[1][1], maxDp[1][2])) + " ");
        System.out.println(Math.min(minDp[1][0], Math.min(minDp[1][1], minDp[1][2])));


        br.close();
    }
}

