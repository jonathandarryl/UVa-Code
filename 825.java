import java.util.*;

class WalkingOnTheSafeSide{
  public static int W,N;
  public static Boolean valid[][];
  public static long memo[][];
  public static void calculate(int x, int y){
    if(x>W || y>N) return;
    if(valid[x][y]){
      memo[x][y] = memo[x-1][y] + memo[x][y-1];
      calculate(x+1,y);
      calculate(x,y+1);
    }
    return;
  }
  public static void main(String[] args){
    StringTokenizer st;
    String str;
    Scanner sc = new Scanner(System.in);
    int tc = sc.nextInt();
    while(tc-->0){
      W = sc.nextInt();N = sc.nextInt();
      valid = new Boolean[W+1][N+1];
      memo = new long[W+1][N+1];
      for(int i=1;i<=W;i++){
        for(int j=1;j<=N;j++){
          memo[i][j] = 0;
          valid[i][j] = true;
        }
      }
      memo[0][1] = 1;
      for(int i=1;i<=W;i++){
        sc.nextInt();
        str = sc.nextLine();
        st = new StringTokenizer(str);
        while(st.hasMoreTokens()){
          valid[i][Integer.valueOf(st.nextToken())] = false;
        }
      }
      calculate(1,1);
      System.out.println(memo[W][N]);
      if(tc!=0)
        System.out.println();
      
    }
  }
}