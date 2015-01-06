import java.util.*;
import java.math.BigInteger;

class FibonacciFreeze{
  public static void main(String[] args){
    Scanner sc= new Scanner (System.in);
    BigInteger[] fib = new BigInteger[5001];
    int input;
    fib[0] = BigInteger.ZERO;
    fib[1] = BigInteger.ONE;
    for(int i=2;i<=5000;i++){
      fib[i] = fib[i-1].add(fib[i-2]);
    }
    while(sc.hasNext()){
      input = sc.nextInt();
      System.out.println("The Fibonacci number for "+input+" is "+fib[input]);
    }
  }
}