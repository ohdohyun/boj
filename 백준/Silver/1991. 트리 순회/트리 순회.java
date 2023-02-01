import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n;
    static int map[][] = new int[27][3];

    static void preOrder(int node) {
        if(node == 0){
            return;
        }
        System.out.print( (char)(node+'A' - 1) );
        preOrder(map[node][0]);
        preOrder(map[node][1]);
    }

    static void inOrder(int node) {
        if(node == 0){
            return;
        }
        inOrder(map[node][0]);
        System.out.print( (char)(node+'A' - 1) );
        inOrder(map[node][1]);
    }

    static void postOrder(int node) {
        if(node == 0){
            return;
        }
        postOrder(map[node][0]);
        postOrder(map[node][1]);
        System.out.print( (char)(node+'A' - 1) );
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        for (int i = 1; i <= n; i++) {
            String input = br.readLine();
            char parent = input.charAt(0);
            char left = input.charAt(2);
            char right = input.charAt(4);

            if (left != '.') {
                map[parent - 'A' + 1][0] = left - 'A' + 1;
            }
            if (right != '.') {
                map[parent - 'A' + 1][1] = right - 'A' + 1;
            }
        }

        preOrder(1);
        System.out.println();
        inOrder(1);
        System.out.println();
        postOrder(1);

        br.close();
    }
}

