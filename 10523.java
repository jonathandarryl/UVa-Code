import java.util.Scanner;
import java.math.BigInteger;

class VeryEasy{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    int N,A;
    while(sc.hasNext()){
      N = sc.nextInt();
      A = sc.nextInt();
      BigInteger temp;
      BigInteger result = BigInteger.ZERO;
      for(int i=1;i<=N;i++){
        BigInteger temp2 = BigInteger.valueOf(A);
        temp = BigInteger.valueOf(i);
        temp2 = temp2.pow(i);
        result = result.add(temp2.multiply(temp));
      }
      System.out.println(result);
    
    
    }
  
  }
}