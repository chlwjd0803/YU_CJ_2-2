import java.util.Scanner;
//intellij 콘솔 한글입력 오류 발생으로 영어로 작성

public class Calculator {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("연산 입력 : ");
        double num1 = sc.nextDouble();
        String opr = sc.next();
        double num2 = sc.nextDouble();
        double result;


        //2018 java 기능추가로
        //case "qwer" -> result = num + num2; 꼴로 할수도 있음
        //break 쓸 필요도 없음

        switch(opr){
            case "sum":
                result = num1 + num2;
                break;
            case "sub":
                result = num1 - num2;
                break;
            case "mul":
                result = num1 * num2;
                break;
            case "div":
                if(num2==0){
                    System.out.println("0으로 나눌 수 없습니다.");
                    return;
                }
                else result = num1 / num2;
                break;
            default:
                System.out.println("사칙연산이 아닙니다.");
                return;
        }
        System.out.println(num1 + " " + opr + " " + num2 + "의 계산결과는 " + result);
    }
}
