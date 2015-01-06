import java.util.*;
import java.math.BigInteger;
class UncleJack{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger i;
    int n;
    while(true){
      i = sc.nextBigInteger();
      n = sc.nextInt();
      if(i.compareTo(BigInteger.ZERO) == 0 && n == 0)
        break;
      i = i.pow(n);
      System.out.println(i);
    }
  }
}