import java.util.Scanner;
import java.math.BigInteger;

class DivisionUVa{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger input1, result1, result2, comp;
    comp = new BigInteger("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    int power1, power2;
    while(sc.hasNext()){
      input1 = sc.nextBigInteger();
      power1 = sc.nextInt();
      power2 = sc.nextInt();
      System.out.print("("+input1+"^"+power1+"-1)/("+input1+"^"+power2+"-1) ");
      result1 = input1.pow(power1);
      result1 = result1.subtract(BigInteger.ONE);
      result2 = input1.pow(power2);
      result2 = result2.subtract(BigInteger.ONE);
      if(result1.compareTo(result2)==-1 || result2.compareTo(BigInteger.ZERO)==0)
        System.out.println("is not an integer with less than 100 digits.");
      else if(result2.compareTo(BigInteger.ONE)!=0 && result1.gcd(result2).compareTo(BigInteger.ONE)==0)
        System.out.println("is not an integer with less than 100 digits.");
      else{
        result1 = result1.divide(result2);
        if(result1.compareTo(comp)==1)
          System.out.println("is not an integer with less than 100 digits.");
        else
          System.out.println(result1);
      }
    }
  }
}