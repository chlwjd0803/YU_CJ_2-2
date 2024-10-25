public class Computer extends Player {
    public Computer(String name) {
        super(name); //슈퍼로 불러와줘야함
    }

    @Override
    public int turn() {
        return (int)(Math.random()*3 + 1);
    }
}
