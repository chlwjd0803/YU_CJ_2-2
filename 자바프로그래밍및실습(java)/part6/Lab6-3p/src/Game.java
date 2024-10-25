public class Game {
    private final String[] s = {"none", "가위", "바위", "보"};
    private Player[] p = new Player[2]; //플레이어 두명 만들어줌


    public Game(){
        p[0] = new Player("정");
        p[1] = new Computer("컴퓨터");
    }

    public Game(Player p0, Player p1){ //플레이어 두명에서 함
        p[0] = p0;
        p[1] = p1;
    }

    public void run(){
        int choice0, choice1;
        while(true){
            choice0 = p[0].turn();
            if(choice0 == 4) break;

            choice1 = p[1].turn(); //난수를 받아올것
            System.out.print(p[0].getName() + "(" + s[choice0] + ") : ");
            System.out.println(p[1].getName() + "(" + s[choice1] + ")");

            int diff = choice0 - choice1;
            switch(diff){
                case 0:
                    System.out.println("비겼습니다");
                    break;

                case -1:
                case 2:
                    System.out.println(p[1].getName() + "가 이겼습니다.");
                    break;

                case 1:
                case -2:
                    System.out.println(p[0].getName() + "가 이겼습니다.");
                    break;

                default:
                    System.out.println("오류가 있었나요?");

            }
        }
    }
}
