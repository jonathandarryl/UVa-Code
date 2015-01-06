import java.util.Scanner;
import java.math.BigInteger;

class Combination{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n,r;
    while(true){
      n = sc.nextInt();
      r = sc.nextInt();
      if(n == 0 && r == 0)
        break;
      BigInteger com = BigInteger.ONE;
      
      System.out.print(n+" things taken "+r+" at a time is ");
      if(r>(n-r))
        r = n-r;
      BigInteger temp;
      for(int i=n;i>(n-r);i--){
        temp = BigInteger.valueOf(i);
        com = com.multiply(temp);
      }
      for(int i=2;i<=r;i++){
        temp = BigInteger.valueOf(i);
        com = com.divide(temp); 
      }
      System.out.println(com+" exactly.");
    }
    return;
  }
}
