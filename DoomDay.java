import java.util.*;

class DoomDay{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int date, month;
    int day;
    Calendar cal = Calendar.getInstance();
    int testcase = sc.nextInt();
    for(int i=0;i<testcase;i++){
      month = sc.nextInt() - 1;
      date = sc.nextInt();
      cal.set(2011,month,date);
      day = cal.get(Calendar.DAY_OF_WEEK);
      if(day == 1)
        System.out.println("Sunday");
      else if(day == 2)
        System.out.println("Monday");
      else if(day == 3)
        System.out.println("Tuesday");
      else if(day == 4)
        System.out.println("Wednesday");
      else if(day == 5)
        System.out.println("Thursday");
      else if(day == 6)
        System.out.println("Friday");
      else if(day == 7)
        System.out.println("Saturday");
    }
  }
}