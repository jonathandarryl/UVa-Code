import java.util.Scanner;
import java.math.BigInteger;

class FibonacciNumbers{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] fib = new BigInteger[4784];
    fib[0] = BigInteger.ONE;
    fib[1] = BigInteger.ONE;
    int input;
    for(int i=2;i<=4783;i++){
      fib[i] = fib[i-1].add(fib[i-2]);
    }
    while(true){
      input = sc.nextInt();
      if(input == 0)
        break;
      System.out.println(fib[input*2-1]);
    }
  }
}