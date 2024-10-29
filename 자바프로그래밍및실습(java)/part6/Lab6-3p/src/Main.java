public class Main {
    public static void main(String[] args) {
        //Game gm = new Game(); //사람vs컴퓨터
        Game gm = new Game(new Player("철수"), new Player("영희")); //사람vs사람
        //Game gm = new Game(new Computer("알파"), new Computer("브라보")); //컴v컴
        gm.run();
    }
}
