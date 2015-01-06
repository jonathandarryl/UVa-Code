import java.util.*;
import java.io.*;
import java.math.BigInteger;

class uva10229{
  static Matrix matMul(Matrix a, Matrix b){
    Matrix ans; int i,j,k;
    ans = new Matrix();
    for(i=0;i<2;i++){
      for(j=0;j<2;j++){
        ans.mat[i][j] = BigInteger.ZERO;
        for(k = 0;k<2; k++)
          ans.mat[i][j] = ans.mat[i][j].add(a.mat[i][k].multiply(b.mat[k][j])); 
                                            
      }
    }
    return ans;
  }
  static Matrix matPow(Matrix base, int p){
    Matrix ans; int i,j;
    ans = new Matrix();
    for(i=0;i<2;i++) for(j=0;j<2;j++) ans.mat[i][j] = (i==j)?BigInteger.ONE:BigInteger.ZERO;
    while(p!=0){
      if(p%2== 1) ans = matMul(ans,base); 
      base = matMul(base,base); p>>=1;
      System.out.println(p);
    }
    return ans;}
  
  public static void main(String[] args){
    PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    Matrix mat = new Matrix();
    mat.mat[0][0] = mat.mat[0][1] = mat.mat[1][0] = BigInteger.ONE;
    mat.mat[1][1] = BigInteger.ZERO;
    while(sc.hasNext()){
      int x, mod;
      x = sc.nextInt();
      mod = sc.nextInt();
      Matrix res = new Matrix();
      res = matPow(mat,x);
      BigInteger result = res.mat[0][1];
      pr.println(result.mod(BigInteger.valueOf(2).pow(mod)));
    }
    pr.close();
  }
  

}

class Matrix{
  BigInteger[][] mat;
  public Matrix(){
    mat = new BigInteger[2][2];
  }
  
}