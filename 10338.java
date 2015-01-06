import java.util.Scanner;
import java.math.BigInteger;

class MischievousChildren{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String letter;
    int test = sc.nextInt();
    int[] alphabet;
    for(int i=1;i<=test;i++){
      letter = sc.next();
      alphabet = new int[26];
      BigInteger result = BigInteger.ONE;
      BigInteger temp;
      for(int j=2;j<=letter.length();j++){
        temp = BigInteger.valueOf(j);
        result = result.multiply(temp);
      }
      for(int j=0;j<letter.length();j++){
        alphabet[(int)letter.charAt(j) - 65]++;
      }
      for(int j=0;j<26;j++){
        while(alphabet[j]>1){
          result = result.divide(BigInteger.valueOf(alphabet[j]));
          alphabet[j]--;
        }
      }
      System.out.println("Data set "+i+": "+result);
    }
  }
}