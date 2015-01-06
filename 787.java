import java.util.*;
import java.math.BigInteger;
class uva787{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] bi = new BigInteger[102];
    int[] zeros = new int[102];
    while(sc.hasNext()){
      int counter = 1;
      for(int i=0;i<102;i++)zeros[i] = 0;
      bi[0] = BigInteger.ONE;
      while(true){
        int x = sc.nextInt();
        if(x == -999999)break;
        if(x==0){
          bi[counter] = BigInteger.ZERO;
          zeros[counter] = 1;
        }else{
          if(zeros[counter-1] == 1){
            bi[counter] = BigInteger.valueOf(x);
          }else{
            bi[counter] = bi[counter-1].multiply(BigInteger.valueOf(x));
          }
        }
        
        counter++;
      }
      BigInteger maximum, current;
      maximum = new BigInteger("-999999999999");
      current = bi[0];
      for(int i=1;i<counter;i++){
        if(zeros[i] == 1){
          if(maximum.compareTo(BigInteger.ZERO) < 0) maximum = BigInteger.ZERO;
        }
        else{
          for(int j=i;j<counter;j++){
            if(zeros[j] == 1) break;
            if(zeros[i-1] == 1){
              current = bi[j];
            }else{
              current = bi[j].divide(bi[i-1]);
            }
            //System.out.println("Current: "+current+" i:"+i+" j:"+j);
            if(maximum.compareTo(current) < 0) maximum = current;
          }
        }
      }
      System.out.println(maximum);
    }
  }
}