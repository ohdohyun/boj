import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int[] alpha;

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

        String input = new String();
        input = br.readLine();

        char standard = input.charAt(input.length() - 1);
//        System.out.println(standard);

        int result = input.length() * 2;
        // 기준 놓고 처음부터 비교
        for (int i = 0; i < input.length(); i++) {
            //같은 문자를 찾으면 팰린드롬인지 체크 후 맞으면 출력해야지 뭐..
            if (input.charAt(i) == standard && isPalindrome(input.substring(i))) {
                result -= input.substring(i).length();
                break;
            }
        }

        System.out.println(result);

        br.close();
    }


}
