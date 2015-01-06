import java.util.Scanner;
import java.util.StringTokenizer;

class Tautogram{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    StringTokenizer st;
    String in, s2;
    boolean tauto;
    while(true){
      in = sc.nextLine();
      if(in.equals("*"))
         break;
      char rem;
      String lower = in.toLowerCase();
      st = new StringTokenizer(lower);
      s2 = st.nextToken();
      tauto = true;
      rem = s2.charAt(0);
      while(st.hasMoreTokens()){
        s2 = st.nextToken();
        if(s2.charAt(0)!=rem){
          tauto = false;
          break;
        }
      }
      if(tauto)
        System.out.println("Y");
      else
        System.out.println("N");
    }
  }
}