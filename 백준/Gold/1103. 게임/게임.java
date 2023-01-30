import javax.swing.event.ListDataListener;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int map[][], visited[][], dp[][];
    static int n, m, maxCount;
    static final int dx[] = {0, 1, 0, -1};
    static final int dy[] = {1, 0, -1, 0};
    static boolean isLoop = false;

    static void back(int x, int y, int cnt) {

        if (dp[x][y] >= cnt) {
            return;
        }
        dp[x][y] = cnt;
        if (maxCount < cnt) {
            maxCount = cnt;
        }
        visited[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i] * map[x][y];
            int ny = y + dy[i] * map[x][y];

            //맵 범위 안인지
            if (nx < 1 || nx > n || ny < 1 || ny > m || map[nx][ny] == -1) {
                continue;
            }
            // 방문 안했으면
            if (visited[nx][ny] == 0) {
                back(nx, ny, cnt + 1);
                if(isLoop)return;
            } else {
                isLoop = true;
                return;
            }

        }
        visited[x][y] = 0;
    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n + 1][m + 1];
        visited = new int[n + 1][m + 1];
        dp = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            String input = new String(br.readLine());
            for (int j = 1; j <= input.length(); j++) {
                if (input.charAt(j - 1) == 'H') {
                    map[i][j] = -1;
                } else {
                    map[i][j] = input.charAt(j - 1) - '0';
                }
            }
        }

        back(1, 1, 1);


        if (isLoop) {
            maxCount = -1;
        }
        System.out.println(maxCount);

//        맵 출력
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }*/


        br.close();
    }
}

