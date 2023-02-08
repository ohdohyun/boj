import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int map[][];
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        map = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            String input = new String(br.readLine());
            for (int j = 0; j < m; j++) {
                if (input.charAt(j) == '0') {
                    map[i][j + 1] = 0;
                } else {
                    map[i][j + 1] = 1;
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] == 1) {
                    map[i][j] = Math.min(map[i - 1][j - 1], Math.min(map[i - 1][j], map[i][j - 1])) + 1;
                    result = Math.max(result, map[i][j]);
                }
            }
        }

        System.out.println(result*result);

    } // main


}

