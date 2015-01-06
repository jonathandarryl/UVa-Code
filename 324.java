import java.util.Scanner;
import java.math.BigInteger;

class FactorialFrequencies{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int test;
    String res;
    int[] digits;
    BigInteger[] fact = new BigInteger [367];
    fact[0] = BigInteger.ONE;
    fact[1] = BigInteger.ONE;
    for(int i=2;i<=366;i++){
      fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
    }
    while(true){
      test = sc.nextInt();
      if(test == 0)
        break;
      res = fact[test].toString();
      digits = new int[10];
      for(int i=0;i<res.length();i++)
        digits[(int)res.charAt(i)-'0']++;
      System.out.println(test+"! --");
      System.out.println("   (0)    "+digits[0]+"    (1)    "+digits[1]+"    (2)    "+digits[2]+"    (3)    "+digits[3]+"    (4)    "+digits[4]);
      System.out.println("   (5)    "+digits[5]+"    (6)    "+digits[6]+"    (7)    "+digits[7]+"    (8)    "+digits[8]+"    (9)    "+digits[9]);
    }
  }
}