import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        HashSet<String> s = new HashSet<>();

        for (int i = 0; i < n; i++) {
            String input = new String(br.readLine());
            char[] temp = input.toCharArray();
            Arrays.sort(temp);
            String sortedString = new String (temp);

            if (!s.contains(sortedString)) { s.add(sortedString); }
        }

        System.out.println(s.size());

        br.close();
    }


}
