import java.util.Scanner;

public class GradeMain {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("수학, 과학, 영어 순으로 3개의 정수 입력 : ");
        var mth = sc.nextInt();
        var sci = sc.nextInt();
        var eng = sc.nextInt();
        Grade grade = new Grade(mth, sci, eng);
        System.out.println(grade.average());

        sc.close();
    }
}