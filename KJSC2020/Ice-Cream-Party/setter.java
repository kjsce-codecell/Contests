// Author : Divesh Thakker
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;


public class Codespree {
	// Ice-Cream Party
	// dp memoized matrix
	static int dp[][] = new int[100003][4];
	public static void main(String [] args) {
		InputReader in = new InputReader(System.in);
		int T = in.readInt();
		while(T-->0){
			int n = in.readInt();
			int arr[] = new int[n+1];
			// makes it necessary to take the n-1 pos in case when cnt=3
			// in rest of cases (cnt=1 and cnt=2) we dont pass this 
			arr[n] = Integer.MAX_VALUE;
			for(int i = 0; i < n; i++) arr[i] = in.readInt();
			for(int [] temp:dp)
			Arrays.fill(temp, -1);
			if(n==0) System.out.println(0);
			else if(n==1) System.out.println(arr[0]);
			// we start with either taking index 0,1 or 2
			else System.out.println(Math.min(recursion(0,1,arr,n-1),Math.min(recursion(1,2,arr,n),recursion(2,3,arr,n+1))));
		}
	}
	
	// i stores the current position
	// cnt is just to represent the i we have stared with
	// first i we can choose is 1,2 or 3..that represents cnt
	static int recursion(int i , int cnt , int arr[],int n){
		if(cnt == 1) {
			if(i+2>=n)return arr[i];
			if(dp[i][cnt]!=-1)return dp[i][cnt];
			else {
				dp[i][cnt] = arr[i] + Math.min(recursion(i+1,cnt,arr,n),Math.min(recursion(i+2,cnt,arr,n),recursion(i+3,cnt,arr,n)));
				return dp[i][cnt];
			}
		} else if(cnt==2) {
			if(i==n)return 0;
			if(dp[i][cnt]!=-1)return dp[i][cnt];
			if(i+2>=n)return arr[i];
			if(i+3==n){ 
				dp[i][cnt]= arr[i]+ Math.min(recursion(i+1,cnt,arr,n),recursion(i+2,cnt,arr,n));
				return dp[i][cnt];
			}
			dp[i][cnt] = arr[i] + Math.min(recursion(i+1,cnt,arr,n),Math.min(recursion(i+2,cnt,arr,n),recursion(i+3,cnt,arr,n)));
			return dp[i][cnt];
		} else {
			if(i==n)return 0;
			if(dp[i][cnt]!=-1)return dp[i][cnt];
			if(i+2>=n)return arr[i];
			if(i+3==n){
				dp[i][cnt]= arr[i]+ Math.min(recursion(i+1,cnt,arr,n),recursion(i+2,cnt,arr,n));
				return dp[i][cnt];
			}
			dp[i][cnt] = arr[i]+ Math.min(recursion(i+1,cnt,arr,n),Math.min(recursion(i+2,cnt,arr,n),recursion(i+3,cnt,arr,n)));
			return dp[i][cnt];
		}
	}
	
	// Code below is just Fast Input
	static class InputReader {
	    private InputStream stream;
	    private byte[] buf = new byte[1024];
	    private int curChar;
	    private int numChars;
	    private SpaceCharFilter filter;
	    public InputReader(InputStream stream) {
	        this.stream = stream;
	    }
	    public int read() {
	        if (numChars == -1)
	            throw new InputMismatchException();
	        if (curChar >= numChars) {
	            curChar = 0;
	            try {
	                numChars = stream.read(buf);
	            } catch (IOException e) {
	                throw new InputMismatchException();
	            }
	            if (numChars <= 0)
	                return -1;
	        }
	        return buf[curChar++];
	    }
	    public int readInt() {
	        int c = read();
	        while (isSpaceChar(c))
	            c = read();
	        int sgn = 1;
	        if (c == '-') {
	            sgn = -1;
	            c = read();
	        }
	        int res = 0;
	        do {
	            if (c < '0' || c > '9')
	                throw new InputMismatchException();
	            res *= 10;
	            res += c - '0';
	            c = read();
	        } while (!isSpaceChar(c));
	        return res * sgn;
	    }
	    public String readString() {
	        int c = read();
	        while (isSpaceChar(c))
	            c = read();
	        StringBuilder res = new StringBuilder();
	        do {
	            res.appendCodePoint(c);
	            c = read();
	        } while (!isSpaceChar(c));
	        return res.toString();
	    }
	    public boolean isSpaceChar(int c) {
	        if (filter != null)
	            return filter.isSpaceChar(c);
	        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	    }
	    public String next() {
	        return readString();
	    }
	    public interface SpaceCharFilter {
	        public boolean isSpaceChar(int ch);
	    }
	}
	 
	static class IOUtils {
	    public static int[] readIntArray(InputReader in, int size) {
	        int[] array = new int[size];
	        for (int i = 0; i < size; i++)
	            array[i] = in.readInt();
	        return array;
	    }
	}
}
