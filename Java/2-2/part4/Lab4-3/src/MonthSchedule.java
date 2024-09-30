import java.util.Scanner;

public class MonthSchedule {
    private Day d[];

    public MonthSchedule(int day){
        d = new Day[day+1];
        for (int i = 0; i < day+1; i++) { // 각 Day 객체 초기화
            d[i] = new Day(); //매우 중요한 작업
        }
    }

    public void input(int day, String work){
        d[day].set(work);
    }

    public void view(int day){d[day].show();}

    public void run(){
        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.print("할일(1:입력, 2:보기, 3:종료) >>> ");
            var slt = sc.nextInt();
            if(slt<1 || slt>3){
                System.out.println("잘못된 입력입니다.");
                continue;
            }
            else if(slt == 3) break;
            System.out.print("날짜?(1~30) : ");
            var day = sc.nextInt();
            if(slt==1){
                System.out.print("할일(빈칸없이) : ");
                String work = sc.next();
                input(day, work);
            }
            else{//이 경우는 어짜피2
                view(day);
            }
        }
        System.out.println("프로그램을 종료합니다.");
        sc.close();
    }

    public static void main(String[] args){
        System.out.println("이번달 스케줄 관리 프로그램.");
        MonthSchedule sep = new MonthSchedule(30);
        sep.run();
    }
}
