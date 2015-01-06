import java.util.*;

class DecodingTheMessage{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String input, temp;
    StringTokenizer st;
    int test = sc.nextInt();
    int counter;
    sc.nextLine();
    sc.nextLine();
    for(int i=1;i<=test;i++){
      System.out.println("Case #"+i+":");
      while(true){
        counter = 0;
        input = sc.nextLine();
        if(input.isEmpty())
          break;
        st = new StringTokenizer(input);
        while(st.hasMoreTokens()){
          temp = st.nextToken();
          if(temp.length()>counter){
            System.out.print(temp.charAt(counter));
            counter++;
          }
        }
        System.out.println();
      }
      if(i!=test)
        System.out.println();
    }
  }
}