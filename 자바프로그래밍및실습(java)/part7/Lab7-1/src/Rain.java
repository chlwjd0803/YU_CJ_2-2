import java.util.*;

public class Rain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        var v = new Vector<Integer>();
        var sum = 0.0;

        while(true){
            System.out.print("강수량 입력 (0입력시 종료) : ");
            int n = sc.nextInt();
            if(n == 0) break;
            v.add(n);
            sum += n;
            for(int i=0; i<v.size(); i++) System.out.print(v.get(i) + " ");
            System.out.println("\n현재평균 : " + (sum / v.size()));
        }
        sc.close();
    }
}
