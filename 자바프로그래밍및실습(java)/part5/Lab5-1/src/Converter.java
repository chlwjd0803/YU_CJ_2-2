import java.util.Scanner;

public abstract class Converter { //public을 붙여도 되고 안붙여도됨
    abstract protected double convert(double src); //추상메소드
    abstract protected String getSrcString(); //추상메소드
    abstract protected String getDstString(); //추상메소드
    protected double ratio; //비율

    public void run(){
        Scanner sc = new Scanner(System.in);
        System.out.println(getSrcString() + "을 " + getDstString() + "로 바꿉니다.");
        System.out.print(getSrcString() + "을 입력하세요");
        var val = sc.nextDouble();
        var res = convert(val);
        System.out.println("변환결과 : " + res + getDstString() + "입니다.");
        sc.close();
    }
}
