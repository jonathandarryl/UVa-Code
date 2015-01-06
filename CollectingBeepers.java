import java.util.*;

class TSPBitmask {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int tc, N, numcity;
    tc = sc.nextInt();
    int[][] matrix, points, dp;
    
    for(int z=0;z<tc;z++) {
      N = sc.nextInt();
      if(N==1){
        sc.nextInt();
        sc.nextInt();
        sc.nextInt();
        System.out.println(0);
      }
      else{
        matrix = new int[N][N];
        points = new int[N][2];
        for (int j = 0; j < N; j++) {
          sc.nextInt();
          points[j][0] = sc.nextInt();
          points[j][1] = sc.nextInt();
        }
        for (int i = 0; i < N; i++){
          for (int j = i+1; j < N; j++) {
            matrix[i][j] = (int)Math.round(Math.sqrt(Math.pow((points[j][0] - points[i][0]),2) + Math.pow((points[j][1] - points[i][1]),2)));
            matrix[j][i] = matrix[i][j];
          }
        }
        
        dp = new int[N][(1 << (N)) + 1];
        for (int i = 0; i < dp.length; i++)
          Arrays.fill(dp[i], -1);

        System.out.println(TSP(0, 0, dp, matrix));
      }
    }
  }
  
  private static int TSP(int node, int bitmask, int[][] dp, int[][] matrix) {
    if (bitmask == (1 << dp.length) - 1 && node == 0)
      return 0;
    if (bitmask == (1 << dp.length) - 1)
      return 100000;
    else if (dp[node][bitmask] != -1){
      return dp[node][bitmask];
    }
    else {
      int min = Integer.MAX_VALUE;
      for (int i = 0; i < dp.length; i++)
        if ((bitmask & (1 << i)) == 0) {
        min = Math.min(min,matrix[node][i] + TSP(i, bitmask | (1 << i), dp, matrix));
      }
      return dp[node][bitmask] = min;
    }
  }
 }