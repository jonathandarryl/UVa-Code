import java.util.Scanner;
import java.util.StringTokenizer;
import java.math.BigInteger;

class Overflow{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String in, input;
    BigInteger input1, input2, comp, result;
    comp = BigInteger.valueOf(Integer.MAX_VALUE);
    result = BigInteger.ZERO;
    while(sc.hasNext()){
      input = sc.nextLine();
      System.out.println(input);
      StringTokenizer st = new StringTokenizer(input);
      input1 = new BigInteger(st.nextToken());
      in = st.nextToken();
      input2 = new BigInteger(st.nextToken());
     
      if(input1.compareTo(comp)==1)
        System.out.println("first number too big");
      if(input2.compareTo(comp)==1)
        System.out.println("second number too big");
      if(in.equals("*"))
        result = input1.multiply(input2);
      else if(in.equals("+"))
        result = input1.add(input2);
      if(result.compareTo(comp)==1)
        System.out.println("result too big");
    }
  }
}