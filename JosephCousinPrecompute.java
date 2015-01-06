class JosephCousinPrecompute{
  public static void main(String[] args){
    int[] isPrime = new int[36212];
    
    int counter = 0;
    for(int i=2;i<=32611;i++){
      if(isPrime[i] == 0){
        System.out.print(i+",");
        counter++;
        for(int j=i+i;j<=32611;j+=i){
          isPrime[j] = 1;
        }
      }
    }

  }
}