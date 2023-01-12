import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int test = 0; test < T; test++) {
            boolean isError = false;
            StringBuilder stringBuilder = new StringBuilder();
            String order = new String(br.readLine());
            int n = Integer.parseInt(br.readLine());
            String input = new String(br.readLine());
            input = input.substring(1, input.length() - 1); // [ ] 제거

            StringTokenizer st = new StringTokenizer(input, ","); // , 제거
            Deque<Integer> dq = new ArrayDeque<>();
            while (st.hasMoreTokens()) {
                dq.addLast(Integer.parseInt(st.nextToken()));
            }

            boolean isReverse = false;
            int sizeOfOrder = order.length();
            for (int i = 0; i < sizeOfOrder; i++) {
                if (order.charAt(i) == 'R') {
                    // R일 경우
                    if (isReverse) {
                        isReverse = false;
                    } else {
                        isReverse = true;
                    }
                } else {
                    //D일 경우
                    if (dq.isEmpty()) {
                        // 없는데 삭제할 경우
                        stringBuilder.append("error");
                        isError = true;
                        break;
                    }
                    if (isReverse == false) {
                        dq.removeFirst();
                    } else {
                        dq.removeLast();
                    }
                }
            }
            // 출력

            if (!stringBuilder.isEmpty()) {

            }
            else if (dq.isEmpty()) {
                //error 출력 이후
                stringBuilder.append("[]");
            } else {
                stringBuilder.append("[");
                if (!isReverse) {
                    //정상순서대로 출력
                    stringBuilder.append(dq.pollFirst());
                    while (!dq.isEmpty()) {
                        stringBuilder.append(",");
                        stringBuilder.append(dq.pollFirst());
                    }
                } else {
                    //역순 출력
                    stringBuilder.append(dq.pollLast());
                    while (!dq.isEmpty()) {
                        stringBuilder.append(",");
                        stringBuilder.append(dq.pollLast());
                    }

                }

                stringBuilder.append("]");
            }

            System.out.println(stringBuilder);
        }


        br.close();
    }
}
