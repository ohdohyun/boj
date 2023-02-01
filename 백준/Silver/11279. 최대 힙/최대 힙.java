import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        PriorityQueue<Integer> mxq = new PriorityQueue<>(Collections.reverseOrder());

        int n = Integer.parseInt(br.readLine());
        int count = 0;
        for (int i = 0; i < n; i++) {
            int input = Integer.parseInt(br.readLine());

            if (input == 0) {
                if (mxq.isEmpty()) {
                    System.out.println("0");
                } else {
                    System.out.println(mxq.poll());
                }
            } else {
                mxq.add(input);
            }
        }



        br.close();
    }
}

