import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Node implements Comparable<Node> {
        public Integer end;
        public Integer cost;

        public Node(Integer end, Integer cost) {
            this.end = end;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(cost, o.cost);
        }
    }

    static int v, e;
    static ArrayList<Node> map[];
    static int answer[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        v = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        map = new ArrayList[v + 1];
        for (int i = 0; i <= v; i++) {
            map[i] = new ArrayList<>();
        }

        answer = new int[v + 1];
        for (int i = 1; i <= v; i++) {
            answer[i] = Integer.MAX_VALUE;
        }

        int k = Integer.parseInt(br.readLine());

        for (int i = 0; i < e; i++) {
            // 간선 입력
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            map[start].add(new Node(end, cost));
        }

        // 다익스트라
        dijkstra(k);

        for (int i = 1; i <= v; i++) {
            if (answer[i] != Integer.MAX_VALUE) {
                System.out.println(answer[i]);
            } else {
                System.out.println("INF");
            }
        }


    } // main

    static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        answer[start] = 0;
        pq.add(new Node(start,0));

        while(!pq.isEmpty()) {
            Node now = pq.poll();

            if(now.cost > answer[now.end]) {
                continue;
            }

            for(Node next : map[now.end]) {
                // 갱신이 필요하면
                if(answer[next.end] > answer[now.end] + next.cost) {
                    answer[next.end] = answer[now.end] + next.cost;
                    pq.add(new Node(next.end, answer[next.end]));
                }
            }

//            printAnswer();
        }
    }

    static void printAnswer(){
        for (int i = 1; i <= v; i++) {
            System.out.print(answer[i] + " ");
        }
        System.out.println();
    }


}

