import java.util.Scanner;
import java.math.BigDecimal;

class BigBigRealNumbers{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int test = sc.nextInt();
    String check;
    BigDecimal bigdec1, bigdec2;
    while(test-->0){
      bigdec1 = new BigDecimal(sc.next());
      bigdec2 = new BigDecimal(sc.next());
      check = bigdec1.add(bigdec2).toPlainString();
      int i = 0;
      while(check.charAt(check.length()-i-1)=='0')
        i++;
      for(int j=0;j<check.length()-i;j++)
        System.out.print(check.charAt(j));
      if(check.charAt(check.length()-i-1) == '.')
        System.out.print("0");
      System.out.println();
    }
  }
}