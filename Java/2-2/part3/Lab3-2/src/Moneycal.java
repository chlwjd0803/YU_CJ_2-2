import java.util.Scanner;

public class Moneycal {
    public static void main(String[] args) {
        int [] unit = {50000, 10000, 1000, 500, 100, 50, 10, 1};
        Scanner sc = new Scanner(System.in);

        System.out.print("금액을 입력하시오 : ");
        var money = sc.nextInt();

        //일반적인 방법
        /*
        for(int i=0; i<unit.length; i++){
            var num = 0;
            while(money >= unit[i]){
                num ++;
                money -= unit[i];
                //money %= unit[i]; //도 가능합니다.
            }
            if(num>0) System.out.println(unit[i] + "원 짜리 : " + num + "개");
        }
        */

        //for-each방식으로 하는법
        for(int u : unit){
            int res = money / u;
            if(res>0){
                System.out.println(u + "원 짜리 : " + res + "개");
                money = money % u;
            }
        }

        sc.close(); //스캐너 종료
    }
}
