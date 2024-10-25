import java.util.*; //안에 캘린더 기능이 있음

public class CurTime {
    public static void main(String[] args){
        Calendar now = Calendar.getInstance(); // Calendar 객체 생성

        int hour = now.get(Calendar.HOUR_OF_DAY);
        int min = now.get(Calendar.MINUTE);

        System.out.println("현재 시각은 " + hour + "시 " + min + "분입니다.");

        if(hour >= 4 && hour < 12) System.out.println("Good Morning");
        else if(hour >= 12 && hour < 18) System.out.println("Good Afternoon");
        else if(hour >= 18 && hour < 10) System.out.println("Good Evening");
        else System.out.println("Good Night");
    }

}
