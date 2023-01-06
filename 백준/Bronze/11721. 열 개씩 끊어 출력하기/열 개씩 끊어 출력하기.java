import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = new String(br.readLine());

        int start = 0;
        while(input.length()>=10){
            System.out.println(input.substring(0, 10));
            input = input.substring(10);
        }
        System.out.println(input);

        br.close();
    }


}
