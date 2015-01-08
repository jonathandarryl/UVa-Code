import java.util.Scanner;
import java.math.BigInteger;

class SimpleBaseConversion{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String in;
    BigInteger x;
    while(true){
      in = sc.next();
      if(in.charAt(0) == '-')
        break;
      if(in.length()>1 && in.charAt(1)=='x'){
        x = new BigInteger(in.substring(2),16);
        System.out.println(x);
      }
      else{
        x = new BigInteger(in);
        System.out.println("0x"+x.toString(16).toUpperCase());
      }
    }
  }
}