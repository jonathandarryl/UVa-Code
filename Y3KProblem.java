import java.util.*;

class Y3KProblem{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int year,month,date, adding;
    Calendar cal = Calendar.getInstance();
    while(true){
      adding = sc.nextInt();
      date = sc.nextInt();
      month = sc.nextInt();
      year = sc.nextInt();
      if(adding == 0 && date == 0 && month == 0 && year == 0)
        break;
      cal.set(year,month-1,date);
      cal.add(Calendar.DATE,adding);
      System.out.println(cal.get(Calendar.DATE)+" "+(cal.get(Calendar.MONTH)+1)+" "+cal.get(Calendar.YEAR));
    }
  }
}