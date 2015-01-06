import java.util.*;
import java.math.BigInteger;

class IntegerInquiry{
  public static void main(String[] args){
    BigInteger sum = BigInteger.ZERO;
    BigInteger sum2;
    Scanner sc = new Scanner(System.in);
    while(true){
      sum2 = sc.nextBigInteger();
      if(sum2.intValue() == 0)
        break;
      sum = sum.add(sum2);
    }
    System.out.println(sum);
    
    return;
  }
}
