import java.util.Scanner;
import java.math.BigInteger;

class Carry{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger input1, input2;
    while(sc.hasNextBigInteger()){
      input1 = sc.nextBigInteger();
      input2 = sc.nextBigInteger();
      System.out.println(input1.xor(input2));
    }
  }
}