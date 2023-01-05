import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int[] alpha;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        alpha = new int[26];
        String input = new String();
        input = br.readLine();
        int count = 0;
        int middle = -1;

        // 입력
        for (int i = 0; i < input.length(); i++) {
            alpha[input.charAt(i) - 'A']++;
        }

        // 되는지 판별 & 홀수인거 빼기
        for (int i=0;i<26;i++) {
            //System.out.println( (char)('A'+ i) + ": " + alpha[i] );
            if(alpha[i] % 2 == 0){continue;}
            if(count==0) {
                count++;
                alpha[i]--;
                middle = i;
            }
            else {
                System.out.println("I'm Sorry Hansoo");
                return;
            }
        }

        for (int i=0;i<26;i++) {
            // A ~ Z 절반출력
            for(int j=0;j<alpha[i]/2;j++){
                System.out.print((char)('A'+i) );
            }
        }

        // middel있으면 출력
        if(middle != -1){
            System.out.print((char)('A'+middle));
        }


        for (int i=25;i>=0;i--) {
            // Z ~ A 절반출력
            for(int j=0;j<alpha[i]/2;j++){
                System.out.print((char)('A'+i) );
            }

        }





        br.close();
    }



}
