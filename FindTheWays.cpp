import java.util.Scanner;
import java.math.BigInteger;

class FindTheWays{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n,r;
    String result;
    while(sc.hasNext()){
      n = sc.nextInt();
      r = sc.nextInt();
      BigInteger com = BigInteger.ONE;
      if(r>(n-r))
        r = n-r;
      BigInteger temp;
      for(int i=n;i>(n-r);i--){
        temp = BigInteger.valueOf(i);
        com = com.multiply(temp);
      }
      for(int i=2;i<=r;i++){
        temp = BigInteger.valueOf(i);
        com = com.divide(temp); 
      }
      result = com.toString();
      System.out.println(result.length());
      
    }
    return;
  }
}
