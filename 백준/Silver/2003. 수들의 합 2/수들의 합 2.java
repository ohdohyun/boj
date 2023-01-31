import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int head = 1, tail = 1;
        int arr[] = new int[n + 2];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int sum = arr[1];
        int count = 0;
        if (sum == m) count++;

        while (tail <= n) {
            //sum이 m보다 작거나 같으면 tail 뒤로
            if (sum <= m) {
                if (tail < n)
                    sum += arr[++tail];
                else
                    break;
            }
            // sum이 크면 -> head를 앞으로
            else {
                if (head == tail) {
                    if (tail < n) {
                        sum += arr[++tail];
                        sum -= arr[head++];
                    }
                    else break;
                } else {
                    sum -= arr[head++];
                }

            }
            if (sum == m) count++;
        }

        System.out.println(count);

        br.close();
    }
}

