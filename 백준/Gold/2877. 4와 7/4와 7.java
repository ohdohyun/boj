import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        StringBuilder str = new StringBuilder();

        arr = new int[31];
        int multiple = 2;
        arr[0] = 1;
        for (int i = 1; i < 31; i++) {
            arr[i] = multiple * arr[i - 1];
        }

        int index = 1;

        while (n > arr[index]) {
            n -= arr[index];
            index++;
        }
        n--;

        String result = Integer.toBinaryString(n);

        while (result.length() < index) {
            result = "0" + result;
        }

//        System.out.println("result: " + result + ", 자릿수: " + index);
        result = result.replace("0", "4");
        result = result.replace("1", "7");

        System.out.println(result);


        br.close();
    }
}
