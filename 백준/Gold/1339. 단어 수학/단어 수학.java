import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int alpha[] = new int[26];

        for (int i = 0; i < n; i++) {
            String input = new String(br.readLine());

            int len = input.length();
            for (int j = 0; j < len; j++) {
                alpha[ (int)input.charAt(j) - 65 ] += (int)Math.pow(10, len - j - 1);
            }
        }

        Arrays.sort(alpha);

        int sum = 0, mul_num = 9;
        for (int i = 25; i >= 0; i--) {
            if (alpha[i] != 0) {
                sum += alpha[i] * mul_num;
                mul_num--;
            }
        }
        
        System.out.println(sum);

        br.close();
    }
}

