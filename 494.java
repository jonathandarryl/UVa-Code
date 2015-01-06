import java.util.Scanner;

class KindergartenCounting{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    boolean found;
    int counter;
    while(sc.hasNext()){
      String input = sc.nextLine();
      counter = 0;
      found = false;
      for(int i=0;i<input.length();i++){
        if(((int)input.charAt(i) >=65 && (int)input.charAt(i) <=90) || ((int)input.charAt(i) >=97 && (int)input.charAt(i) <=122)){
          if(!found){
            counter++;
            found = true;
          }
        }
        else
          found = false;
      }
      System.out.println(counter);
    }
  }
}
