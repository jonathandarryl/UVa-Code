import java.util.Scanner;
import java.math.BigInteger;

class Krakovia{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int counter = 1;
    int numbill, friends;
    while(true){
      BigInteger total = BigInteger.ZERO;
      numbill = sc.nextInt();
      friends = sc.nextInt();
      BigInteger fr = BigInteger.valueOf(friends);
      if(numbill == 0 && friends == 0)
        break;
      for(int i=0;i<numbill;i++){
        total = total.add(sc.nextBigInteger());
      }
      System.out.println("Bill #"+counter+" costs "+total+": each friend should pay "+total.divide(fr));
      System.out.println();
      counter++;
    }
    return;
  }
}