import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

//        int T = Integer.parseInt(br.readLine());

        // n 입력
        int n = Integer.parseInt(br.readLine());
        Integer arr[] = new Integer[n];

        //구간 입력
        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        //k입력
        int k = Integer.parseInt(br.readLine());

        //구간i,j 초기화해서 더하기
        int i = 0, j = 0;
        long sum = arr[0];
        long count = 0;
        while (j < n) {
            // j가 i보다 작으면 j++ continue
            if (j < i) {
                j++;
                continue;
            }
            //이미 값이 크면 뒷구간 개수만큼 count+, i++, sum-arr[i]
            if (sum > k) {
                count += n - j;
                sum -= arr[i++];
            } else if (++j < n) {
                sum += arr[j];
            }
        }

        System.out.println(count);

        br.close();
    }
}
