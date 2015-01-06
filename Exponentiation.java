import java.util.*;
import java.math.BigDecimal;

class Exponentiation{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigDecimal x;
    int n,zero;
    String check;
    while(sc.hasNext()){
      x = sc.nextBigDecimal();
      n = sc.nextInt();
      x = x.pow(n);
      check = x.toPlainString();
      int i = 0;
      while(check.charAt(check.length()-i-1)=='0')
        i++;
      if(x.compareTo(BigDecimal.ONE)==-1){
        for(int j=1;j<check.length()-i;j++)
          System.out.print(check.charAt(j));
      }
      else{
        for(int j=0;j<check.length()-i;j++)
          System.out.print(check.charAt(j));
      }
      System.out.println();
        
    }
  }
}