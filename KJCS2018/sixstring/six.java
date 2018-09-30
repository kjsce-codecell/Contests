import java.util.*;
class  six{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        //System.out.println("");
        while(t-->0){
            char [] str=sc.next().toCharArray();
            //System.out.println(Arrays.toString(str));
            long ans=0;
            boolean modsum[] =new boolean[3];
            for (int i=0;i<str.length;++i){


            if(str[i]=='1' || str[i] == '6'){

                 ans+=10;
                 modsum=new boolean[3];
             }
                else{
                    int digit=Integer.parseInt(""+str[i]);
                    boolean psdo[] = new boolean[3];

                    for (int j=0;j<3;++j){
                        if(modsum[j]){
                            psdo[(j+digit)%3]=true;
                            }

                    }
                    psdo[digit%3]=true;
                    if(psdo[0]&&digit%2==0){
                        ans+=5;
                        modsum=new boolean[3];
                    }
                    else modsum=psdo;

                }
            }
            System.out.println(ans);
        }
    }
}
