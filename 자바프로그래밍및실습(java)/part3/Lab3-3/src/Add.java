//명령형 인자의 관한 중요내용 포함
//String[] args에 관련한 내용

public class Add {
    public static void main(String[] args) {
        var sum = 0;
        //내코드
        for(var i=0; i<args.length; i++){
            try{sum += Integer.parseInt(args[i]);} //NumberFormatException
            catch (NumberFormatException e) {} //예외가 발생할때 아무 짓도 하지 않겠다.(연산을 하지 않겠다)
            //예외 타입을 단순히 적은것
        }
        System.out.println("내 코드 합 : " + sum);

        //교수님 코드 for-each 이용
        //아래 경우를 시험문제를 출제할 확률이 높음
        sum = 0;
        for(String s: args){
            try {sum += Integer.parseInt(s);}
            catch (NumberFormatException e) {System.out.println(s + "는 정수가 아님");}
            //교수님 코드는 예외가 발생함을 출력해주는 꼴
            //예외 타입을 자세히 해주는게 좋음
            //문자열을 변환하는 과정에서 예외가 발생하므로 NumberFormatException
        }
        System.out.println("교수님코드 합 : " + sum);
    }
}
