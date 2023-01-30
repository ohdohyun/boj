import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int x_y[] = new int[33];
    static int y_x[] = new int[33];
    static int col[] = new int[16];
    static int n;
    static int count = 0;

    static void rec(int r) {

        if (r == n) {
            count++;
            return;
        }

        for (int i = 0; i < n; i++) {
            // 0~n까지 퀸 놓기
            if (x_y[n + r - i] == 1 || y_x[i + r] == 1 || col[i] == 1) {
                continue;
            }
            x_y[n + r - i] = 1;
            y_x[i + r] = 1;
            col[i] = 1;
            rec(r + 1);
            x_y[n + r - i] = 0;
            y_x[i + r] = 0;
            col[i] = 0;


        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        rec(0);

        System.out.println(count);


        br.close();
    }
}