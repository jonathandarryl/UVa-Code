import java.util.Scanner;
import java.math.BigInteger;

class BasicRemains{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String in;
    int base;
    BigInteger x,y;
    while(true){
      base = sc.nextInt();
      if(base == 0)
        break;
      in = sc.next();
      x = new BigInteger(in,base);
      in = sc.next();
      y = new BigInteger(in,base);
      x = x.mod(y);
      System.out.println(x.toString(base));
    }
  }
}