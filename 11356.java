import java.util.*;

class Dates{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int test, jump, month;
    Integer year, day;
    StringTokenizer st;
    String input, mth;
    test = sc.nextInt();
    for(int i=1;i<=test;i++){
      System.out.print("Case "+i+": ");
      input = sc.next();
      st = new StringTokenizer(input,"-");
      input = st.nextToken();
      
      year = (input.charAt(0)-'0')*1000 + (input.charAt(1)-'0')*100 + (input.charAt(2)-'0')*10 + (input.charAt(3)-'0');
      mth = st.nextToken();
      input = st.nextToken();
      day = (input.charAt(0) - '0')*10 + input.charAt(1)-'0';
      if(mth.equals("January"))
        month = 0;
      else if(mth.equals("February"))
        month = 1;
      else if(mth.equals("March"))
        month = 2;
      else if(mth.equals("April"))
        month = 3;
      else if(mth.equals("May"))
        month = 4;
      else if(mth.equals("June"))
        month = 5;
      else if(mth.equals("July"))
        month = 6;
      else if(mth.equals("August"))
        month = 7;
      else if(mth.equals("September"))
        month = 8;
      else if(mth.equals("October"))
        month = 9;
      else if(mth.equals("November"))
        month = 10;
      else 
        month = 11;
      Calendar cal = Calendar.getInstance();
      cal.set(year,month,day);
      jump = sc.nextInt();
      cal.add(Calendar.DATE,jump);
      year = cal.get(Calendar.YEAR);
      month = cal.get(Calendar.MONTH);
      day = cal.get(Calendar.DATE);
      System.out.print(year+"-");
      if(month == 0)
        mth = "January";
      else if(month == 1)
        mth = "February";
      else if(month == 2)
        mth = "March";
      else if(month == 3)
        mth ="April";
      else if(month == 4)
        mth = "May";
      else if(month == 5)
        mth = "June";
      else if(month == 6)
        mth = "July";
      else if(month == 7)
        mth = "August";
      else if(month == 8)
        mth = "September";
      else if(month == 9)
        mth = "October";
      else if(month == 10)
        mth = "November";
      else
        mth = "December";
      System.out.print(mth+"-");
      if(day<10)
        System.out.print("0");
      System.out.println(day);
      
    }
  }
}