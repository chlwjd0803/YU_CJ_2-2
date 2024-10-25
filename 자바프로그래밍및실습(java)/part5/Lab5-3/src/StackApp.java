import java.util.Scanner;

public class StackApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("총 스택 저장공간의 크기를 입력 : ");
        var capacity = sc.nextInt();
        StringStack ss = new StringStack(capacity);

        while(true){
            System.out.print("문자열 입력 : ");
            String str = sc.next();
            if(str.equals("그만")) break; //시험 출제 가능
            if(ss.push(str) == false) { //푸시를 실행하며 Stack full 검사
                System.out.println("스택이 꽉 차서 푸시 불가");
                continue;
            }
        }

        System.out.print("스택에 저장된 모든 문자열 팝 : ");
        for(int i=0; i<ss.length(); i++){System.out.print(ss.pop() + " ");} //241024 논리오류수정

        sc.close();
    }
}
