import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static StringTokenizer st;
    static int arrA[];
    static int sumArrA[];
    static int arrB[];
    static int sumArrB[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        ////////// 모든 경우의 서브배열 합 저장 /////////
        int n = Integer.parseInt(br.readLine());
        arrA = new int[n];
        sumArrA = new int[n * (n + 1) / 2];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arrA[i] = Integer.parseInt(st.nextToken());
        }

        int index = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arrA[j];
                sumArrA[index++] = sum;
            }
        }

        int m = Integer.parseInt(br.readLine());
        arrB = new int[m];
        sumArrB = new int[m * (m + 1) / 2];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            arrB[i] = Integer.parseInt(st.nextToken());
        }
        index = 0;
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = i; j < m; j++) {
                sum += arrB[j];
                sumArrB[index++] = sum;
            }
        }

        Arrays.sort(sumArrA);
        Arrays.sort(sumArrB);

        /////////// 투포인터 ////////////

        int headA = 0, tailB = sumArrB.length - 1;
        long count = 0;
        while (headA < sumArrA.length && tailB >= 0) {
            int sum = sumArrA[headA] + sumArrB[tailB];

            if (sum == T) {
                int tempA = sumArrA[headA];
                int tempB = sumArrB[tailB];
                long countSameA = 0;
                long countSameB = 0;

                while (headA < sumArrA.length && sumArrA[headA] == tempA) {
                    headA++;
                    countSameA++;
                }
                while (tailB >= 0 && sumArrB[tailB] == tempB) {
                    tailB--;
                    countSameB++;
                }
                count += countSameA * countSameB;

            } else if (sum < T) {
                headA++;
            } else if (sum > T) {
                tailB--;
            }

        }

        System.out.println(count);


        br.close();
    }
}

