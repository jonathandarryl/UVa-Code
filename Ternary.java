import java.math.BigInteger;
import java.util.*;

class Ternary{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String check;
    BigInteger x;
    while(true){
      check = sc.next();
      if(check.charAt(0) == '-')
        break;
      x = new BigInteger(check);
      System.out.println(x.toString(16));
    }
  }
}