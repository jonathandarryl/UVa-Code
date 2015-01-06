import java.util.Scanner;
import java.math.BigInteger;

class isLeapYear{
  public static void main(String[] args){
    BigInteger year;
    boolean isLeap, isHuluculu, isBulukulu, first = true;
    Scanner sc = new Scanner(System.in);
    while(sc.hasNext()){
      if(!first)
        System.out.println();
      first = false;
      isLeap = false;
      isHuluculu = false;
      isBulukulu = false;
      year = sc.nextBigInteger();
      if(year.mod(BigInteger.valueOf(400)).compareTo(BigInteger.ZERO) == 0 || (year.mod(BigInteger.valueOf(4)).compareTo(BigInteger.ZERO) == 0 && year.mod(BigInteger.valueOf(100)).compareTo(BigInteger.ZERO) != 0)){
        isLeap = true;
        System.out.println("This is leap year.");
      }
      if(year.mod(BigInteger.valueOf(15)).compareTo(BigInteger.ZERO) == 0){
        isHuluculu = true;
        System.out.println("This is huluculu festival year.");
      }
      if(isLeap && year.mod(BigInteger.valueOf(55)).compareTo(BigInteger.ZERO) == 0){
        isBulukulu = true;
        System.out.println("This is bulukulu festival year.");
      }
      if(!isLeap && !isHuluculu && !isBulukulu)
        System.out.println("This is an ordinary year.");
      
    }
  }
}