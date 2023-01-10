import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = new String(br.readLine());
        StringTokenizer st = new StringTokenizer(input);

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        HashSet<String> nonehear = new HashSet<>();
        ArrayList<String> non = new ArrayList<String>();
        int count = 0;

        for(int i=0;i<n;i++){
            input = br.readLine();
            nonehear.add(input);
        }

        for (int i = 0; i < m; i++) {
            input = br.readLine();
            if (nonehear.contains(input)) {
                count++;
                non.add(input);
            }
        }

        Collections.sort(non);
        System.out.println(count);
        for(int i=0;i<count;i++){
            System.out.println(non.get(i));
        }

        br.close();
    }


}
