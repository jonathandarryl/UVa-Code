
import java.math.BigInteger;

class PreCompute{
    public static void main(String[] args){
      BigInteger input;
      input = BigInteger.ONE;
      for(int i=1;i<=10000;i++){
        input = input.multiply(BigInteger.valueOf(i));
        while(BigInteger.ZERO.compareTo(input.mod(BigInteger.TEN))==0){
            input = input.divide(BigInteger.TEN);
        }
        System.out.print(input.mod(BigInteger.TEN)+",");

      }
    }
}