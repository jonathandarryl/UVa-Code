import java.math.BigInteger;
import java.util.Scanner;

class BigMod{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger B, P, M;
    while(sc.hasNextBigInteger()){
      B = sc.nextBigInteger();
      P = sc.nextBigInteger();
      M = sc.nextBigInteger();
      System.out.println(B.modPow(P,M));
    }
  }
}