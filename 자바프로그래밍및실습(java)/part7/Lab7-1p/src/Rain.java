import java.util.*;


//다른함수로구현 + 이터레이터 사용으로 내코드보다 더 응용됨
public class Rain {
    public static void print(Vector<Integer> v){
        //메인에서 부르기위해, static은 static만 부를 수 있기 때문이다
        //자바는 기본적으로 포인터 개념이 따로 존재하지 않아서 필드가 아니면 객체나 배열은 무조건 참조형으로
        double sum = 0.0;
        Iterator<Integer> it = v.iterator(); //중요한 형태 꼭 암기하기, 기출문제
        while(it.hasNext()){ //hasNext() 기출문제
            int n = it.next(); //해당 이터레이터가 가르키는 값을 반환하고 다음 원소로 넘어감
            sum += n;
            System.out.print(n+" "); //문자열로 출력하기위해 "" 붙임
        }
        System.out.println("\n평균 : " + (sum/v.size()));
    }

    public static void main(String[] args) {
        var sc = new Scanner(System.in);
        var v = new Vector<Integer>(); //Vector<Integer> v = new Vector<Integer>(여기 들어가는 수는 초기용량);
        while(true){
            System.out.print("강수량 입력 (0 입력시 종료) : ");
            int n = sc.nextInt();
            if(n == 0) break;
            v.add(n);
            print(v); //static 메소드 접근
        }
        sc.close();
    }

}
