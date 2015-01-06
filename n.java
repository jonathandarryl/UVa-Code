import java.util.*;

class n{
  public static void main(String[] main){
    Scanner sc = new Scanner(System.in);
    int i, j, max, counter, divided;
    while(sc.hasNext()){
      i = sc.nextInt();
      j = sc.nextInt();
   
      System.out.print(i+" "+j+" ");
      max = 0;
      for(int k=Math.min(i,j);k<=Math.max(i,j);k++){
        counter = 1;
        divided = k;
        while(divided>1){
          if(divided%2==0)
            divided/=2;
          else
            divided = 3*divided + 1;
          counter++;
        }
        if(counter>max)
          max = counter;
      }
      System.out.println(max);
    }
  }
}