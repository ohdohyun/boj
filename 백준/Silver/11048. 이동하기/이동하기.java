import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    static int dp[][];
    static int map[][];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        StringTokenizer st = new StringTokenizer(str, " ");
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        dp = new int[n+1][m+1];
        map = new int[n+1][m+1];
        for(int i=1;i<=n;i++){
            String input = br.readLine();
            st=new StringTokenizer(input," ");
            for(int j=1;j<=m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = Math.max(map[i][j] + dp[i-1][j-1], Math.max(map[i][j] + dp[i-1][j], map[i][j] + dp[i][j-1]));
            }
        }
        
        System.out.println(dp[n][m]);

        br.close();
    }
}
