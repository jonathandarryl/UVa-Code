import java.util.Scanner;
import java.math.BigInteger;

class Multipleof17{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger input;
    while(true){
      input = sc.nextBigInteger();
      if(input.intValue() == 0)
        break;
      if(input.mod(BigInteger.valueOf(17)) == BigInteger.ZERO)
        System.out.println("1");
      else
        System.out.println("0");
    }
  }
}
