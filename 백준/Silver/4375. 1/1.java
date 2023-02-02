import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }

    static int func(int div) {
        int num = 1;
        int count = 1;
        while (num % div != 0) {
            num = num * 10 + 1;
            num %= div;
            count++;
        }
        return count;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        while((str = br.readLine() ) != null){
            int n = Integer.parseInt(str);

            System.out.println(func(n));
        }



        br.close();
    }
}

