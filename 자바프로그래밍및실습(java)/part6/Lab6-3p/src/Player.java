import java.util.Scanner;

public class Player {
    private String name;
    private Scanner sc = new Scanner(System.in);

    public Player(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int turn(){
        System.out.print(name + " 가위1 바위2 보3 끝내기4 : ");
        return sc.nextInt();
    }
}
