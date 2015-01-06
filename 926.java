import java.util.*;

class WalkingAroundWisely{
  public static int N;
  public static int endR,endC,startR,startC;
  public static long[][] ways;
  public static Boolean[][][] valid;
  
  public static long calculate(int x, int y){
    if(x == endR || y == endC) return 1;
    else if(x>endR || y> endC) return 0;
    //for(int i=1;i<=N;i++){
      //for(int j=1;j<=N;j++)
        //System.out.print(ways[i][j]);
      //System.out.println();
    //}
    //System.out.println();
    if(ways[x][y]!=-1) return ways[x][y];
    
    long ans = 0;
    if(valid[x][y][1])
      ans+=calculate(x+1,y);
    if(valid[x][y][0])
      ans+=calculate(x,y+1);
    ways[x][y] = ans;
    return ways[x][y];
  }
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int tc = sc.nextInt();
    int halangan;
    while(tc-->0){
      N = sc.nextInt();
      ways = new long[N+1][N+1];
      valid = new Boolean[N+1][N+1][2];
      startR = sc.nextInt();
      startC = sc.nextInt();
      endR = sc.nextInt();
      endC = sc.nextInt();
      halangan = sc.nextInt();
      for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
          ways[i][j] = -1;
          valid[i][j][0] = valid[i][j][1] = true;
        }
      }
      //ways[endR][endC] = 1;
      for(int i=0;i<halangan;i++){
        int x = sc.nextInt();
        int y = sc.nextInt();
        String dir = sc.next();
        if(dir.contains("W")){
          valid[x-1][y][1] = false;
        }
        else if(dir.contains("E")){
          valid[x][y][1] = false;
        }
        else if(dir.contains("N")){
          valid[x][y][0] = false;
        }
        else if(dir.contains("S")){
          valid[x][y-1][0] = false;
        }
      }
      
      System.out.println(calculate(startR,startC));
      //if(ways[endR][endC] == -1)
        //System.out.println("0");
      //else
        //System.out.println(ways[][]);
    }
  }
}