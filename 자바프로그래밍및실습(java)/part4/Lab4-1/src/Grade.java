import java.util.InputMismatchException;
import java.util.Scanner;

public class Grade {
    private int mth;
    private int sci;
    private int eng;

    public Grade(int mth, int sci, int eng){
        this.mth = mth;
        this.sci = sci;
        this.eng = eng;
    }

    public double average(){return (double)(mth + sci + eng) / 3;}


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int mth;
        int sci;
        int eng;

        while(true) { //그냥 예외처리추가해봄
            try {
                System.out.print("수학, 과학, 영어 순으로 3개의 정수 입력 : ");
                mth = sc.nextInt();
                sci = sc.nextInt();
                eng = sc.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("정수가 아닌값이 존재합니다.");
                sc.nextLine(); //반드시처리
                continue;
            }
            break;
        }
        Grade grade = new Grade(mth, sci, eng);
        System.out.println(grade.average());

        sc.close();
    }
}
