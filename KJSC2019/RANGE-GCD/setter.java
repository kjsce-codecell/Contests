import java.io.ByteArrayInputStream;
        import java.io.IOException;
        import java.io.InputStream;
        import java.io.PrintWriter;
        import java.util.*;
        import java.io.*;
        public class Main {
        InputStream is;
            PrintWriter out;
            String INPUT = "";
        //class Declaration
        static class pair implements Comparable<pair>{
            int x,y;
            
            pair (int i,int j)
            { x=i; y=j;
                
            }
            public int compareTo(pair p){
                if(this.x!=p.x) { return this.x-p.x;}
                else { return this.y-p.y;}
            }
            public int hashCode() { return (x+" "+y).hashCode();}
            public String toString(){ return x+" "+y;}
            public boolean equals(Object o){
                pair x = (pair) o ;
                return (x.x==this.x&&x.y==this.y);}
        }
long [] arr,block ;
int l,r,blk_sz,n,t;
void solve(){

        t=ni();
        for(int z=0;z<t;z++)
        {
            n=ni();
            int q= ni();
            
            arr = new long[n];
            for(int i=0;i<n;++i) arr[i]=nl();
            preprocess();
        
            while(q-->0){
                int option = ni();
                if(option==1){
                    
                    pn(query(ni(),ni()));
                }
                else{
                    int ll=ni(),rr=ni();
                    long xx=nl();
                    //pn("getting "+ll+" "+rr+" "+xx);
                    update( ll,rr,xx );
                    //pn(Arrays.toString(block));
                    //pn(Arrays.toString(arr));

                }
                
            }
        }
}


// Taken from Geeksforgeeks.com

void updateBlock(int blkNm){
    long g = arr[(int)Math.min(blkNm*blk_sz,n-1)];
    for(int i=blkNm*blk_sz;i<n;++i){
        g=gcd(g,arr[i]);
        if(i%blk_sz==blk_sz-1) break;
    }
    if(block[blkNm]/g >1){
        
        long mul = block[blkNm]/g;
        for(int i=blkNm*blk_sz;i<n;++i){
            arr[i]*=mul;
            if(i%blk_sz==blk_sz-1) break;
        }
        
    }
}
long query(int l, int r){
    updateBlock(l/blk_sz);
    updateBlock(r/blk_sz);
    long g = arr[l];
    boolean f=true;
    while (l<r && l%blk_sz!=0 && l!=0)
{
        // traversing first block in range 
        
g = gcd(arr[l],g);
l++;
    }
    //pn("int "+g); 
    while (l+blk_sz <= r)
{
        // traversing completely overlapped blocks in range 
g = gcd(g,block[l/blk_sz]);
l += blk_sz;
    }
    f=true;
    while (l<=r)
{
        
        // traversing last block in range 
g = gcd(g,arr[l]);
l++;
}
    return g;
}
void update(int l,int r, long x){
    
    updateBlock(l/blk_sz);
    updateBlock(r/blk_sz);


//  pn("updating "+l+" "+r+" "+x);
    int templ= l;
    int tempr=r;


    boolean firstBlk=true,lastBlk=true;
    while (l<r && l%blk_sz!=0 && l!=0)
{
        
        // traversing first block in range 
arr[l] *= x;
l++;
    }
    
    //actually Multplying for partially filled parts and updating gcd of block 
    long partG=arr[(int)(templ/blk_sz)*blk_sz];
    for(int ind=(templ/blk_sz)*blk_sz,j=0;j<blk_sz && ind+j<n ;++j){
        //pn("doing "+arr[ind+j]);
        partG = gcd (partG,arr[ind+j]);
    }
    //pn("Part g "+partG);
    block[(int)(templ/blk_sz)] = partG;


    
    while (l+blk_sz <= r)
{
        // traversing completely overlapped blocks in range 
block[l/blk_sz] *= x;
l += blk_sz;
}
    while (l<=r)
{

        
        // traversing last block in range 
        arr[l] *= x;
       
l++;
    }


     partG=arr[(int)(tempr/blk_sz)*blk_sz];
    for(int ind=(tempr/blk_sz)*blk_sz,j=0;j<blk_sz && ind+j<n ;++j){
        partG = gcd (partG,arr[ind+j]);
    }
    block[(int)(tempr/blk_sz)] = partG;
    //pn("Part g end "+partG);
    //pn(Arrays.toString(block));
    
}
  

void preprocess(){
    // initiating block pointer 
    int blk_idx = -1;
  
    // calculating size of block 
    blk_sz =(int) Math.ceil(Math.sqrt(n));
    //pn("blk_Sz "+blk_sz);
    block = new long[blk_sz+1];
    //vis = new boolean[blk_sz+1];

    Arrays.fill(block,1L);

  
    // building the decomposed array 
    for (int i=0; i<n; i++)
{
        
        if (i%blk_sz == 0)
{
            // entering next block 
            // incementing block pointer 
            blk_idx++;
            block[blk_idx]= arr[i];
}
block[blk_idx] = gcd(arr[i],block[blk_idx]);
    }
    //pn(Arrays.toString(block)); 
}



    int gcd(int a, int b)
    {
    if (b == 0)
        return a;
    return gcd(b, a % b);
    }
    long gcd(long a, long b)
    {
    if (b == 0)
        return a;
    return gcd(b, a % b);
    }


        void run() throws Exception
        {
                is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
                out = new PrintWriter(System.out);
                
                long s = System.currentTimeMillis();
                solve();
                out.flush();
                if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
        }
            
            
            public static void main(String[] args) throws Exception { new Main().run(); }
            
        //output methods
        private void pn(Object o)
        {
            out.println(o);
        }
        private void p(Object o)
        {
            out.print(o);
        }



        //input methods
                private byte[] inbuf = new byte[1024];
            public int lenbuf = 0, ptrbuf = 0;
            

            private int readByte()
            {
                if(lenbuf == -1)throw new InputMismatchException();
                if(ptrbuf >= lenbuf){
                    ptrbuf = 0;
                    try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
                    if(lenbuf <= 0)return -1;
                }
                return inbuf[ptrbuf++];
            }
            
            private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
            private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
            
            private double nd() { return Double.parseDouble(ns()); }
            private char nc() { return (char)skip(); }
            
            private String ns()
            {
                int b = skip();
                StringBuilder sb = new StringBuilder();
                while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
                    sb.appendCodePoint(b);
                    b = readByte();
                }
                return sb.toString();
            }
            
            private char[] ns(int n)
            {
                char[] buf = new char[n];
                int b = skip(), p = 0;
                while(p < n && !(isSpaceChar(b))){
                    buf[p++] = (char)b;
                    b = readByte();
                }
                return n == p ? buf : Arrays.copyOf(buf, p);
            }
                
            private char[][] nm(int n, int m)
            {
                char[][] map = new char[n][];
                for(int i = 0;i < n;i++)map[i] = ns(m);
                return map;
            }
            
            private int[] na(int n)
            {
                int[] a = new int[n];
                for(int i = 0;i < n;i++)a[i] = ni();
                return a;
            }
            
            private int ni()
            {
                int num = 0, b;
                boolean minus = false;
                while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
                if(b == '-'){
                    minus = true;
                    b = readByte();
                }
                
                while(true){
                    if(b >= '0' && b <= '9'){
                        num = num * 10 + (b - '0');
                    }else{
                        return minus ? -num : num;
                    }
                    b = readByte();
                }
            }
            
            private long nl()
            {
                long num = 0;
                int b;
                boolean minus = false;
                while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
                if(b == '-'){
                    minus = true;
                    b = readByte();
                }
                
                while(true){
                    if(b >= '0' && b <= '9'){
                        num = num * 10 + (b - '0');
                    }else{
                        return minus ? -num : num;
                    }
                    b = readByte();
                }
            }
            
            private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(Arrays.deepToString(o)); }
        }