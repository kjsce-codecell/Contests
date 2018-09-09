import java.util.*;

public class setter {
    public static void main(String[] args) {
        // System.out.println("Hello world!");
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int h, m, s, x;
        while (t-- > 0) {
            // System.out.println("Hello world!");
            h = sc.nextInt();
            m = sc.nextInt();
            s = sc.nextInt();
            x = sc.nextInt();
            x = x % 360;
            m += (x * 2);
            h += m / 60;
            m = m % 60;
            h = h % 12;
            if (h == 0)
                h = 12;
            System.out.println(h + " " + m + " " + s);
        }
    }
}
