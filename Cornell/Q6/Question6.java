import java.util.*;
public class Question6 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        long n = s.nextLong();
        int r = s.nextInt();
        int q = s.nextInt();
        long[][] rli = new long[r][2];
        long[] qli = new long[q];
        for (int i = r-1; i >= 0; i--) {
            rli[i][0] = s.nextLong();
            rli[i][1] = s.nextLong();
        }
        for (int j = 0; j < q; j++) {
            qli[j] = s.nextLong();
        }
        for (long i: qli) {
            for (long[] j: rli) {
                if (i <= j[1] && i >= j[0]) {
                    i = j[1]+j[0]-i;
                }
            }
            System.out.println(i);
        }
    }
}