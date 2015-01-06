import java.util.Scanner;
import java.math.BigInteger;

class IfWeWereaChildAgain{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String test;
    BigInteger input1, input2;
    while(sc.hasNext()){
      input1 = sc.nextBigInteger();
      test = sc.next();
      input2 = sc.nextBigInteger();
      if(test.equals("/")){
        System.out.println(input1.divide(input2));
      }
      else if(test.equals("%")){
        System.out.println(input1.mod(input2));
      }
    
    }
  }
}