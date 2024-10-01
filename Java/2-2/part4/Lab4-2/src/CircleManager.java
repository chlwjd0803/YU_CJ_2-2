import java.util.Scanner;

public class CircleManager {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Circle c[] = new Circle[3]; //배열의 크기는 초기화, 배열의 원소는 초기화되지않음
        for(int i = 0; i < c.length; i++){
            System.out.print("x, y, radius : ");
            var x = sc.nextDouble();
            var y = sc.nextDouble();
            var radius = sc.nextInt();
            c[i] = new Circle(x, y, radius); //각 배열의 원소 초기화
        }
        //for(int i = 0; i < c.length; i++) c[i].show();
        for (Circle circle : c) circle.show(); //for-each iterator 원리 이용, 값을 읽어올때 용이
        sc.close();
    }
}
