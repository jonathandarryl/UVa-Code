import java.util.Scanner;
import java.math.BigInteger;

class Product{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger temp;
    while(sc.hasNextBigInteger()){
      temp = sc.nextBigInteger();
      temp = temp.multiply(sc.nextBigInteger());
      System.out.println(temp);
    }
  }
}