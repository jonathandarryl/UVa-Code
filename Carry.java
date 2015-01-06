import java.util.*;

class Carry{
  public static void main(String[] args){
    int i,j, carry, tempi, tempj, hascarry;
    Scanner sc = new Scanner(System.in);
    i = sc.nextInt();
    j = sc.nextInt();
    while(i!=0 && j!=0){
      carry = 0;
      hascarry = 0;
      while(i!=0 && j!=0){
        tempi = i%10;
        tempj = j%10;
        i/=10;
        j/=10;
        if((tempi+tempj)>9 ||(hascarry==1 && tempi + tempj>8)){
          carry++;
          hascarry = 1;
        }
        else
          hascarry = 0;
      }
      if(carry==0){
        System.out.println("No carry operation.");
      }
      else if(carry==1){
        System.out.println("1 carry operation.");
      }
      else
        System.out.println(carry+" carry operations.");
        i = sc.nextInt();
        j = sc.nextInt();
    }
  }
}
