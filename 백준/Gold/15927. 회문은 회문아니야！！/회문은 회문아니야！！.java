import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static boolean isPalindrome(String str) {
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = new String(br.readLine());

        int start = 0;
        int end = str.length() - 1;

        for (int i = 0; i <= end; i++) {
            if (str.charAt(start) != str.charAt(i)) {
                break;
            } else if (i == end) {
                System.out.println(-1);
                return;
            }
        }

        if (isPalindrome(str)) {
            System.out.println(str.length() - 1);
        } else {
            System.out.println(str.length());
        }

        br.close();
    }
}
