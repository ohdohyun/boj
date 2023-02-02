import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int divNum = 2;
        while (n > 1) {
            while (n % divNum == 0) {
                n /= divNum;
                System.out.println(divNum);
            }
            divNum++;
        }


        br.close();
    }
}

