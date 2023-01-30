import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int l, c;
    static String alpha[];

    static void result(int count, int index, String ans) {
        //조건 만족시 체크&출력
        if (count == l) {
            char temp;
            int aeiou = 0;
            for (int i = 0; i < l; i++) {
                temp = ans.charAt(i);
                if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
                    aeiou++;
                }
            }

            if (aeiou >= 1 && l - aeiou >= 2) {
                System.out.println(ans);
            }
        }
        //다시 돌려야지.. for문...
        for (int i = index + 1; i < c; i++) {
            result(count + 1, i, ans+alpha[i]);
        }


    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = new String(br.readLine());
        StringTokenizer st = new StringTokenizer(input);

        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        alpha = new String[c];
        for (int i = 0; i < c; i++) {
            alpha[i] = st.nextToken();
        }
        Arrays.sort(alpha);

        result(0, -1, "");


        br.close();
    }
}

