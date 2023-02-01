import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static long arr[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        PriorityQueue<Long> pq = new PriorityQueue<>();
        arr = new long[k];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < k; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            pq.add(arr[i]);
        }

        long result = 0;
        for (int i = 1; i <= n; i++) {
            result = pq.poll();
            while (!pq.isEmpty() && pq.peek() == result) {
                pq.poll();
            }

            for (int j = 0; j < k; j++) {
                pq.add(arr[j] * result);
                if (result % arr[j] == 0) {
                    break;
                }
            }
        }

        System.out.println(result);







        br.close();
    }
}

