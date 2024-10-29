package base; //컴파일하여 base 패키지에 저장할 것을 지시함

public class Shape {
    //public 말고 dafault 로 하면 (아무것도 안붙이면) 같은 패키지 안에서만 사용권한
    //이들은 다른 패키지이므로 public선언을 반드시 해야한다.
    public void draw(){
        System.out.println("Shape");
    }
}
