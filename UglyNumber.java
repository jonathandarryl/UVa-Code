

class UglyNumber{
  public static void main(String[] args){
    int ugly = 2;
    int counter = 1, i;
    boolean isugly = true;
    while(true){
      i=2;
      while(ugly>=i){
        if((ugly%i==0) && (i%2!=0 && i%3!=0 && i%5!=0)){      
            isugly = false;
           
            break;
           
        }
        i++;
      }
      if(isugly){
        counter++;

      }
      if(counter==1500)
        break;
      ugly++;
      isugly = true;
    }
   System.out.println(ugly);

  }
}
