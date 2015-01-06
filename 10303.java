import java.util.*;
import java.math.BigInteger;

class HowManyTrees{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int test, in;
    BigInteger[] trees = new BigInteger[1001];
    trees[0] = BigInteger.ONE;
    for(int i=0;i<1000;i++){
      test = (2*(i)+2)*(2*(i)+1);
      trees[i+1] = BigInteger.valueOf(test).multiply(trees[i]);
      trees[i+1] = trees[i+1].divide(BigInteger.valueOf((i+2)*(i+1)));
    }
    while(sc.hasNext()){
      in = sc.nextInt();
      System.out.println(trees[in]);
    }
    
  }
}