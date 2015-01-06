import java.util.Scanner;
import java.math.BigInteger;

class WhoSaidCrisis{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int testcase;
    BigInteger input1, input2;
    testcase = sc.nextInt();
    for(int i=0;i<testcase;i++){
      input1 = sc.nextBigInteger();
      input2 = sc.nextBigInteger();
      System.out.println(input1.subtract(input2));
    }
  }
}