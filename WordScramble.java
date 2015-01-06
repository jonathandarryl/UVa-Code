import java.util.Scanner;
import java.util.StringTokenizer;

class WordScramble{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    StringTokenizer st;
    String input;
    boolean first;
    while(sc.hasNextLine()){
      input = sc.nextLine();
      st = new StringTokenizer(input);
      first = true;
      while(st.hasMoreTokens()){
        if(!first)
          System.out.print(" ");
        first = false;
        input = st.nextToken();
        for(int i=0;i<input.length();i++){
          System.out.print(input.charAt(input.length()-i-1));
        }
      }
      System.out.println();
    }
  }
}