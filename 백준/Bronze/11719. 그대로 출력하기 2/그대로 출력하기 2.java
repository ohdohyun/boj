import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int n;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        String input = new String();

        while ((input = br.readLine()) != null) {
            System.out.println(input);
        }

        br.close();
    }



}
