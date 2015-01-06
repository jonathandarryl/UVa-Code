import java.util.Scanner;
import java.math.BigInteger;

class MODEX{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger x;
    int y,n;
    int test = sc.nextInt();
    for(int i=0;i<test;i++){
      x = sc.nextBigInteger();
      y = sc.nextInt();
      n = sc.nextInt();
      System.out.println(x.modPow(BigInteger.valueOf(y),BigInteger.valueOf(n)));
    }
    sc.nextInt();
  }
}