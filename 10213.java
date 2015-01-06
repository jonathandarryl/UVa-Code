import java.util.Scanner;
import java.math.BigInteger;

class HowManyPieces{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger n,result,temp;
    String in;
    while(sc.hasNext()){
      in = sc.next();
      n = new BigInteger(in);
      temp = n;
     
      result = new BigInteger("24");
      result = result.subtract(n.multiply(BigInteger.valueOf(18)));
      n = n.multiply(temp);
      result = result.add(n.multiply(BigInteger.valueOf(23)));
      n = n.multiply(temp);
      result = result.subtract(n.multiply(BigInteger.valueOf(6)));
      n = n.multiply(temp);
      result = result.add(n);
      result = result.divide(BigInteger.valueOf(24));
      System.out.println(result);
    }
  }
}