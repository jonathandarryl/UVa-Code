import java.util.Scanner;
import java.math.BigInteger;

class BrickWallPatterns{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] fib = new BigInteger[51];
    fib[0] = BigInteger.ONE;
    fib[1] = BigInteger.ONE.add(BigInteger.ONE);
    for(int i=2;i<=50;i++){
      fib[i] = fib[i-1].add(fib[i-2]);
    }
    int input;
    while(true){
      input = sc.nextInt();
      if(input == 0)
        break;
      System.out.println(fib[input - 1]);
    }
  }
}