import java.util.*;
class Train{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        assert t>=1 && t<=1000;
    
        while(t-->0){
            long n=sc.nextLong(),m=sc.nextLong();
            long limit=(long)1e18;
            assert n>=1 && n<=limit && m>=1 && m<=10 ;
    
            ArrayList<Long> v=new ArrayList<>();
            for(int i=0;i<m;++i) {
                long x=sc.nextLong();
                assert x>=0 && x<=limit ;
                v.add(x+1);
            }
            long ans=inclu_exclu(v,n);
            System.out.println(n-ans); 
    
    
    
        }

     
    }
static long inclu_exclu(ArrayList<Long> v,long num){
        long N=v.size(),pow=(1<<N),sum=0;
           for(int i=1;i<pow;++i){
               long ct=1;
               for(int k=0;k<N;k++){ 
                if((i&(1<<k))>=1){
                    ct=lcm(ct,v.get(k));
                    if(ct<0) {
                        //System.out.println("-v");
                        break;
                        
                    }
                    
                }
               }
               if(ct>=0){
               if((Integer.bitCount(i))%2==1) sum+=(num/ct);
               else  sum-=(num/ct);
               }
           }
           return sum;
       }
       static long lcm(long x,long y){
                long result = x*y;
                if( x != 0 && result/x != y) return -1l;
                long g=gcd(x,y);
                long ans=(x*y)/g;
                return ans;
       }
static long gcd(long x,long y){
             if(y==0) return x;
             return gcd(y,x%y);
       }
       
}
