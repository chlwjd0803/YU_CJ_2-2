import java.util.Scanner;

public class RPSgame {
    Scanner sc;

    public RPSgame(){sc = new Scanner(System.in);}

    public void end(){sc.close();}

    public void prtWinner(Player p, Computer c) {
        if(p.rps == c.rps) System.out.println("비겼습니다.");
        else{
            switch(p.rps) {
                case 1:{
                    if(c.rps==3) System.out.println("컴퓨터가 이겼습니다");

                }
            }
        }
    }



    public void run(){
        Player p = new Player();
        Computer c = new Computer();

        while(true){
            System.out.print("플레이어[가위1, 바위2, 보3, 끝내기4] : ");
            var n = sc.nextInt();

            if(n==4) break; //끝내기

            p.setRps(n); //플레이어 설정
            c.setRps(); //컴퓨터 랜덤설정

            System.out.print("플레이어 : " + p.getRps() + " / ");
            System.out.println("컴퓨터 : " + c.getRps());





        }

        end();
    }
}
