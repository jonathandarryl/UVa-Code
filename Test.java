class Test{
  public static void main(String[] args){
    int counter, digit,howmany;
    counter = 1;
    digit = 1;
    howmany = 0;
    while(digit<100000){
      digit = (int)Math.pow(counter,2);
      System.out.print(digit+",");
      counter++;
      howmany++;
    }
    System.out.println();
    System.out.print(howmany);
  }
}