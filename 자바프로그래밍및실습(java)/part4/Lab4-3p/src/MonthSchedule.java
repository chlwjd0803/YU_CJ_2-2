import java.util.Scanner;

public class MonthSchedule {
    private int nDays;
    private Day[] days;
    private Scanner scanner;

    public MonthSchedule(int nDays) {
        this.nDays = nDays;
        days = new Day[nDays];
        scanner = new Scanner(System.in);
    }

    private void input(){
        System.out.print("날짜(1~"+nDays+")?");
        var day = getInt();
        System.out.print("할일(빈칸없이) : ");
        String work = scanner.next();
        day--; //인덱스값과 맞춰주는 연산(0부터)
        if(day<0 || day >= nDays){
            System.out.println("날짜 입력 오류");
            return;
        }

        days[day] = new Day(); //객체 초기화!,입력할때 시켜주는 상황
        days[day].set(work);
    }

    private void view(){
        System.out.print("날짜(1~"+nDays+")?");
        var day = getInt();
        day--; //인덱스와 맞춤
        if(day<0 || day >= nDays){
            System.out.println("날짜 입력 오류");
            return;
        }
        System.out.print((day+1) + "일의 할일은 ");
        if(days[day] != null) days[day].show();
        else System.out.println("없습니다.");
    }

    private void finish(){
        scanner.close(); //스캐너 닫기
        System.out.println("종료합니다.");
    }

    public void run(){
        System.out.println("이번달 스케줄 관리 프로그램.");
        while(true){
            System.out.print("할일(1:입력, 2:보기, 3:종료) : ");
            var menu = getInt();
            switch(menu){ //스위치문을 활용할것
                case 1-> input();
                case 2-> view();
                case 3-> {
                    finish();
                    return;
                }
                default -> System.out.println("메뉴 선택 오류");
            }
        }
    }

    private int getInt(){ //예외처리가 권장되는 방법은 아님, boolean 타입을 쓰는것이 더 적합
        while(true){
            try{
                var num = scanner.nextInt();
                return num;
            } catch(NumberFormatException e){
                System.out.println("정수를 입력하세요.");
                scanner.nextLine();
            }
        }
    }
}
