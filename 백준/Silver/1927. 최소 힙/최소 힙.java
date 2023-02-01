import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        PriorityQueue<Integer> mnq = new PriorityQueue<>();

        int n = Integer.parseInt(br.readLine());
        int count = 0;
        for (int i = 0; i < n; i++) {
            int input = Integer.parseInt(br.readLine());

            if (input == 0) {
                if (mnq.isEmpty()) {
                    System.out.println("0");
                } else {
                    System.out.println(mnq.poll());
                }
            } else {
                mnq.add(input);
            }
        }



        br.close();
    }
}

