import java.util.Scanner;

public class Refrigerator {
    public static void main(String[] args){
        final byte POW = 0b1; //이진수 형태로 표현한것
        final byte DOOR = 0b10;
        final byte LAMP = 0b100;
        final byte TEMP = 0b1000;

        Scanner sc = new Scanner(System.in);
        System.out.print("냉장고 상태 입력 : ");
        String str = sc.next();
        byte status = Byte.parseByte(str, 2); //문자열을 2진수로 만들어 바이트 타입의 정수로 저장

        //정상인 상태를 1, 변화/이상이 있으면 0
        if((status & POW) == 0) System.out.print("전원꺼져있음. ");
        else System.out.print("전원켜져있음. ");
        if((status & DOOR) == 0) System.out.print("문 열려있음. ");
        else System.out.print("문 닫혀있음. ");
        if((status & LAMP) == 0) System.out.print("전구이상발생. ");
        else System.out.print("전구정상작동. ");
        if((status & TEMP) == 0) System.out.print("냉장고온도 3도 이상. ");
        else System.out.print("냉장고온도 3도 미만. ");
    }
}
