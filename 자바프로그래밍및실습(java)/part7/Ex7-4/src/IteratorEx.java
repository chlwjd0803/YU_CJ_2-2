import java.util.*;

public class IteratorEx {
    public static void main(String[] args) {
        var v = new Vector<Integer>();
        v.add(5);
        v.add(4);
        v.add(-1);
        v.add(2, 100);

        Iterator<Integer> it = v.iterator(); //반드시 타입 매개변수 명시할것
        var sum = 0;

        //주의. it.next를 실행할경우 계속 다음으로 넘어가므로 중복 이용시 값을 저장해둘것
        while(it.hasNext()){ //이터레이터가 가르키는 주소가 유효하면 지속
            int n = it.next();
            System.out.println(n);
            sum += n;
        }
        System.out.println("벡터에 있는 정수 합 : " + sum);
    }
}