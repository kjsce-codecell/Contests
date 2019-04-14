import java.util.*;
import java.lang.Math;
class Main
{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a,b,x,n;
		int t=sc.nextInt();
		while(t-- > 0)
		{
			a=sc.nextInt();
			b=sc.nextInt();
			x=sc.nextInt();
			n=(int)Math.floor(((b-a)/x)+1);
			System.out.println(n);
		}
	}
}