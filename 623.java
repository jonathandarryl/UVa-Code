import java.util.Scanner;
import java.math.BigInteger;

class Fact500{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int test;
    BigInteger[] fact = new BigInteger [1001];
    fact[0] = BigInteger.ONE;
    fact[1] = BigInteger.ONE;
    for(int i=2;i<=1000;i++){
      fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
    }
    while(sc.hasNext()){
      test = sc.nextInt();
      System.out.println(test+"!");
      System.out.println(fact[test]);
    }
  }
}