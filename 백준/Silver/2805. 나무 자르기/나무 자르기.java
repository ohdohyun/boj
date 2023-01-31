import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int arr[];

    static long returnSum(int height) {
        long sum = 0;
        for (int e : arr) {
            if (e > height) {
                sum += e - height;
            }
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // given
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int maxNum = 0;
        arr = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            maxNum = Math.max(maxNum, arr[i]);
        }

        //
        int head = 0, tail = maxNum;
        while (head < tail) {
            int body = (head + tail) / 2;
            long _returnSum = returnSum(body);

            if (_returnSum == m) {
                System.out.println(body);
                return;
            }

            if (_returnSum < m) tail = body;
            else if (_returnSum > m) head = body + 1;
        }

        System.out.println(head - 1);

        br.close();
    }
}

