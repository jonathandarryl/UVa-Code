import java.util.Scanner;
import java.math.BigInteger;

class WorldCupNoise{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int test = sc.nextInt();
    BigInteger[] fib = new BigInteger[53];
    
    fib[0] = BigInteger.ONE.add(BigInteger.ONE);
    fib[1] = fib[0].add(BigInteger.ONE);
    for(int i=2;i<=52;i++){
      fib[i] = fib[i-1].add(fib[i-2]);
    }
    for(int i=1;i<=test;i++){
      System.out.println("Scenario #"+i+":");
      System.out.println(fib[sc.nextInt()-1]);
      System.out.println();
    }
  }
}