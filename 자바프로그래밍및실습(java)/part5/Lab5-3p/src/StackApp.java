import java.util.Scanner;

public class StackApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("스택 크기 : ");
        var capacity = sc.nextInt();
        StringStack ss = new StringStack(capacity);

        while(true){
            System.out.print("문자열 : ");
            String str = sc.next();
            if(str.equals("그만")) break; //시험출제가능
            boolean res = ss.push(str);
            if(!res) System.out.println("Stack Full!!!");
        }
        System.out.print("스택의 모든 문자 : ");
        for(int i=0; i<ss.length(); i++) System.out.print(ss.pop() + " "); //잘 동작함
        /*
        while (ss.length() > 0) {
            System.out.print(ss.pop() + " ");
        }
        */
        System.out.println();

        sc.close();
    }
}
