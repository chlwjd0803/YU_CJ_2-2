import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        var test = sc.nextInt(); // 시험장의 개수
        int [] per = new int[test];

        for(var i = 0; i < test; i++) per[i] = sc.nextInt(); //각 시험장에 있는 응시자의 수

        var mn = sc.nextInt(); //총감독관
        var sb = sc.nextInt(); //부감독관
        long cnt = 0; //감독관의 수 오버플로우 고려하여 long형으로 선언

        for(var i = 0; i < test; i++){
            per[i]-=mn;
            cnt++; //총 감독관이 들어가므로
            if(per[i]>0) cnt+=(per[i]+sb-1)/sb;
        }
        System.out.print(cnt);
        sc.close();
    }
}