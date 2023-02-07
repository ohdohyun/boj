import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Map;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    static int n,m;
    static ArrayList<Integer> map[];
    static int searchOrder[];
    static boolean answer[];
    static int order = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            map[i] = new ArrayList<>();
        }
        searchOrder = new int[n + 1];
        answer = new boolean[n + 1];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            map[a].add(b);
            map[b].add(a);
        }

        // dfs로 방문
        for (int i = 1; i <= n; i++) {
            if (searchOrder[i] == 0) {
                dfs(i, true);
            }
        }

        // 단절점 출력
        String answerString = "";
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (answer[i]) {
                count++;
                answerString += i + " ";
            }
        }

        System.out.println(count);
        System.out.println(answerString);
    }

    static int dfs(int now, boolean isStart) {
        order++;
        searchOrder[now] = order;
        int child = 0;
        int minLow = order;

        for (int next : map[now]) {
            if (searchOrder[next] == 0) {
                // 아직 방문전이므로 방문
                child++;

                int nextLow = dfs(next, false);
                
                // next가 단절점인지 판별
                if (isStart == false && nextLow >= searchOrder[now]) {
                    answer[now] = true;
                }
                minLow = Math.min(minLow, nextLow);
            } else {
                // 이미 방문했으면 최소 order값만 카피해옴
                minLow = Math.min(minLow, searchOrder[next]);
            }
        }

        // now(시작루트)가 단절점인지
        if (isStart == true && child >= 2) {
            answer[now] = true;
        }

        return minLow;
    }
}

