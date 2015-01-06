import java.util.*;
class Three{
  public static void main(String[] args){
    boolean found = false;
    int asdf;
    for(int i=1;i<=50000;i++){
      found = false;
      if(i%8!=7){
        asdf = (int)Math.sqrt(i);
        for(int j=0;j<=asdf;j++){
          for(int k=j;k<=asdf;k++){
            for(int l=k;l<=asdf;l++){
              if(j*j + k*k + l*l == i){
                System.out.print("\""+j+" "+k+" "+l+"\"");
                found = true;
                break;
              }
            }
            if(found)
              break;
          }
          if(found)
            break;
        }
      }
      if(!found)
        System.out.print("\"-1\"");
      System.out.print(",");
    }
    
  }
}
