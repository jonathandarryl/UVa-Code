import java.util.*;
import java.math.BigDecimal;

class HighPrecisionNumber{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigDecimal input;
    String a, check;
    int test;
    test = sc.nextInt();
    for(int i=0;i<test;i++){
      input = BigDecimal.ZERO;
      while(true){
        a = sc.next();
        if(a.length()==1 && a.equals("0"))
          break;
        input = input.add(new BigDecimal(a));
      }
      check = input.toPlainString();
      int k=0; 
      while(check.charAt(check.length()-k-1)=='0')
        k++;
      for(int j=0;j<check.length()-k-1;j++)
        System.out.print(check.charAt(j));
      if(check.charAt(check.length()-k-2)!='.')
        System.out.print(check.charAt(check.length()-k-2));
      System.out.println();
    }
  }
}