import java.util.*;
import java.math.BigInteger;

class CounttheTrees{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int test, in;
    BigInteger[] trees = new BigInteger[301];
    trees[0] = BigInteger.ONE;
    for(int i=0;i<300;i++){
      test = (2*(i)+2)*(2*(i)+1);
      trees[i+1] = BigInteger.valueOf(test).multiply(trees[i]);
      trees[i+1] = trees[i+1].multiply(BigInteger.valueOf(i+1));
      trees[i+1] = trees[i+1].divide(BigInteger.valueOf((i+2)*(i+1)));
    }
    while(true){
      in = sc.nextInt();
      if(in == 0)
        break;
      System.out.println(trees[in]);
    }
    
  }
}