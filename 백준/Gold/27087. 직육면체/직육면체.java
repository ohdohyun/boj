import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for(int i=0;i<T;i++) {
            String str = br.readLine();
            StringTokenizer st = new StringTokenizer(str, " ");
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());

            int cnt = 0;
            if (A % P == 0) cnt++;
            if (B % P == 0) cnt++;
            if (C % P == 0) cnt++;
            if (cnt >= 2) System.out.println(1);
            else System.out.println(0);
        }


        br.close();
    }
}
