import java.util.Scanner;
import java.math.BigInteger;

class RayThroughGlasses{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] fib = new BigInteger[1001];
    fib[0] = BigInteger.ONE;
    fib[1] = BigInteger.ONE.add(BigInteger.ONE);
    for(int i=2;i<=1000;i++){
      fib[i] = fib[i-1].add(fib[i-2]);
    }
    while(sc.hasNext()){
      System.out.println(fib[sc.nextInt()]);
    }
  }
}