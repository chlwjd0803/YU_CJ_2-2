import java.util.Vector;

public class VectorEx {
    public static void main(String[] args){
        var v = new Vector<Integer>();

        v.add(5);
        v.add(4);
        v.add(-1);

        v.add(2, 100); //인덱스 2번에 원소 10을 넣겠다는 뜻

        System.out.println("벡터 내의 요소 객체 수 : " + v.size());
        System.out.println("벡터의 현재 용량 : " + v.capacity());
        System.out.println("벡터의 현재 길이 : " + v.size());

        //모든 요소 정수 출력하기
        for(var i=0; i<v.size(); i++){
            int n = v.get(i);
            System.out.println(n);
        }

        //벡터 속의 모든 정수 더하기
        int sum = 0;
        for(var i=0; i<v.size(); i++){
            sum += v.get(i);
        }
        System.out.println("벡터에 있는 정수 합 : " + sum);
    }
}