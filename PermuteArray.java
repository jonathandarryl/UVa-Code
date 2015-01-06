import java.util.Scanner;
import java.util.StringTokenizer;

class PermuteArray{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int test = sc.nextInt();
    int counter;
    String[] in = new String[500000];
    int[] perm = new int[100000];
    String input;
    sc.nextLine();
    for(int i=0;i<test;i++){
      sc.nextLine();
      input = sc.nextLine();
      counter = 0;
      StringTokenizer st = new StringTokenizer(input);
      while(st.hasMoreTokens()){
        perm[counter] = Integer.valueOf(st.nextToken());
        counter++;
      }
      input = sc.nextLine();
      st = new StringTokenizer(input);
      for(int j=0;j<counter;j++){
        in[perm[j]-1] = st.nextToken();
      }
      for(int j=0;j<counter;j++)
        System.out.println(in[j]);
      if(i!=test-1)
        System.out.println();
    }
  }
}
