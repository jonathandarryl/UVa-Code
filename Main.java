import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main{
  public static void main(String[] args)throws NumberFormatException,
   IOException{
    BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    String test, test2;
    boolean isWord;
    int count;
    while(true){
      test2 = buff.readLine();
      if(test2 == "")
        break;
      st = new StringTokenizer(test2);
      
      count = 0;
      while(st.hasMoreTokens()){
        isWord = false;
        test = st.nextToken();
        for(int i=0;i<test.length();i++){
          if((int)test.charAt(i)>64 && (int)test.charAt(i)<128){
            isWord = true;
            break;
          }
        }
        if(isWord)
        count++;
      }
      System.out.println(count);
    }
  }
}