public class CircleArea {
    //함수형태를 만들기위해 public static 선언
    public static void main(String[] args){
        final double PI = 3.14; //원주율을 상수로 선언(상수는 모두 대문자로 지정 권장)

        //var로 변수타입 생략한것(double형)
        var radius = 10.0;
        var circleArea = radius*radius*PI;

        //원의 면적을 화면에 출력한다. 출력방식 익히기
        System.out.println("원의 면적 = " + circleArea);
    }
}