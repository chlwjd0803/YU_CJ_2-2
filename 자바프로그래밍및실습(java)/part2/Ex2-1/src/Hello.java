/*
* 소스파일 : Hello.java
* 학습을 위해 직접작성
 */

//Hello 이름의 클래스 선언
public class Hello {
    public static int sum(int n, int m){
        return n+m;
    }

    //main() 메소드에서 실행 시작
    public static void main(String[] args){
        //지역변수
        int i = 20;
        int s;
        char a;

        s = sum(i, 10);
        a = '?';
        //자바의 출력방식
        System.out.println(a);
        System.out.println("Hello");
        System.out.println(s);
    }
}