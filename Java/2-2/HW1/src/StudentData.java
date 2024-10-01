import java.util.InputMismatchException;
import java.util.Scanner;

public class StudentData {
    private Scanner sc; //스캐너 선언
    private int per = 10; //총 학생수
    private int [] snum = new int[per]; //학번
    private int [] score = new int[per]; //점수

    public StudentData() {sc = new Scanner(System.in);} //생성자와 동시에 스캐너 할당

    private void invalid_ipt(){ //예외처리 시 사용하는 출력과 처리
        System.out.println("잘못된 입력입니다.");
        sc.nextLine();
    }

    private void input() { //초기 학생자료 입력
        System.out.println("10명 학생의 학번과 점수입력");
        for(var i=0; i<per; i++) {
            System.out.print((i+1) + "번째 학생 : ");
            try{
                snum[i] = sc.nextInt();
                score[i] = sc.nextInt();
            } catch(InputMismatchException e) { //자료형 비일치 예외
                invalid_ipt();
                i--; //재입력 해야되므로 index값 감소
            }
        }
    }

    private void srch_snum(){
        var num = 0;//초기화만
        while(true){
            System.out.print("학번 : ");
            try{
                num = sc.nextInt();
            } catch(InputMismatchException e) { //자료형 비일치 예외
                invalid_ipt();
                continue;
            }
            break;
        }

        int i;
        for(i=0; i<per; i++) if(snum[i] == num) break;
        if(i<per) System.out.println(score[i] + "점");  //break로 인해 해당 인덱스를 이용하여 점수출력
        else System.out.println(num+"의 학생은 없습니다."); //반복문이 작동할동안 찾지못함
    }

    private void srch_score(){
        var num = 0;//초기화만
        while(true){
            System.out.print("점수 : ");
            try{
                num = sc.nextInt();
            } catch(InputMismatchException e) { //자료형 비일치 예외
                invalid_ipt();
                continue;
            }
            break;
        }
        System.out.print("점수가 "+num+"인 학생은 ");
        int i;
        boolean flag = false; //시작은 하나도 못찾은 상태로 시작

        for(i=0; i<per; i++) if(score[i] == num){
            System.out.print(snum[i] + " ");
            flag = true; //1개이상 찾은경우
        }
        if(flag) System.out.println("입니다.");
        else System.out.println("없습니다.");
    }

    private void finish(){
        System.out.println("프로그램을 종료합니다.");
        sc.close(); //스캐너 할당 해제
    }

    private void search_menu(){
        while(true){
            System.out.print("1.학번검색 / 2.점수검색 / 3.종료 : "); //검색 메뉴들
            int mnu;
            try{
                mnu = sc.nextInt();
            } catch(InputMismatchException e) { //자료형 비일치 예외
                invalid_ipt();
                continue;
            }

            switch(mnu){
                case 1-> srch_snum(); //1.학번검색
                case 2-> srch_score(); //2.점수검색
                case 3 -> { //3.종료
                    return; //종료되면 자동으로 run에있는 다음함수인 finish로 넘어감
                }
                default -> System.out.println("잘못된 선택입니다."); //123 외 다른값
            }
        }
    }

    public void run(){
        input(); //초기 학생 학번 입력
        search_menu(); //검색 본메뉴
        finish(); //종료 작업
    }

    public static void main(String[] args) {
        StudentData sd = new StudentData(); //객체생성
        sd.run(); //객체에서 실행
    }
}