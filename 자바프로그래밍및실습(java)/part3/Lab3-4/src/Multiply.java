import java.util.InputMismatchException; //예외 클래스
import java.util.Scanner;

public class Multiply {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.print("곱하고자 하는 두 정수 입력 : ");
            try{
                var x = sc.nextInt();
                var y = sc.nextInt();
                System.out.print(x + " * " + y + " = " + x*y);
                break;
            }
            catch(InputMismatchException e){
                String ex = sc.nextLine();
                System.out.println(ex + "는 정수가 아닙니다. 다시 입력해주세요."); //이런식으로 잘못된 걸 바로 받아서 출력할 수 있음

                /*
                System.out.println("정수타입이 아닌 것이 입력되었습니다. 다시 입력해주세요.");
                sc.nextLine(); //C++의 버퍼비우기와 유사한 개념, 이미 입력된키를 제거함, 숙지하기

                 */
            }
        }
        sc.close(); //스캐너 종료
    }
}
