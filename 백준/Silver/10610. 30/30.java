import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        int sum = 0;
        int numArr[] = new int[10];
        boolean isZero = false;
        for (int i = 0; i < input.length(); i++) {
            int temp = input.charAt(i) - '0';
            if (temp == 0) {
                isZero = true;
            }
            sum += temp;
            numArr[temp]++;
        }

        if (!isZero || sum % 3 != 0) {
            System.out.println(-1);
        } else {
            int index = 9;
            while (index >= 0) {
                while (numArr[index] > 0) {
                    System.out.print(index);
                    numArr[index]--;
                }
                index--;
            }


        }

        br.close();
    }
}

