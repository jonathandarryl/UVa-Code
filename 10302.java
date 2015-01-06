import java.util.Scanner;
import java.math.BigInteger;

class SummationofPolynomials{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] num = new BigInteger[50000];
    int input;
    num[0] = BigInteger.ONE;
    for(int i=2;i<=50000;i++){
      num[i-1] = num[i-2].add(BigInteger.valueOf(i).pow(3));
    }
    while(sc.hasNext()){
      input = sc.nextInt();
      System.out.println(num[input-1]);
    }
  }
}