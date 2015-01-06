import java.util.*;
import java.math.BigInteger;

class Fibinary{
  public static void main(String[] args){
    BigInteger[] fib = new BigInteger[101];
    fib[0] = BigInteger.ONE;
    fib[1] = BigInteger.valueOf(2);
    for(int i=2;i<=100;i++)
      fib[i] = fib[i-1].subtract(fib[i-2]);
    String input1, input2;
    while(){
      input1 = sc.next();
      input2 = sc.next();
      int length;
      BigInteger num1;
      num1 = BigInteger.ZERO;
      length = input1.length();
      int counter = 0;
      for(int i=length-1;i>=0;i--){
        num1 = num1.add(BigInteger.valueOf(input1.at(i)).multiply(fib[counter++]));
      }
      length = input2.length();
      counter = 0;
      for(int i=length-1;i>=0;i--){
        num1 = num1.add(BigInteger.valueOf(input1.at(i)).multiply(fib[counter++]));
      }
      boolean first = true;
      for(int i=100;i>=0;i--){
        if(num1.compare()){
          num1 = num1.subtract(fib[i]);
          System.out.print("1");
          first = false;
        }
        else if(false)
          System.out.print("0");
      }
      System.out.println();
    }
  }
}