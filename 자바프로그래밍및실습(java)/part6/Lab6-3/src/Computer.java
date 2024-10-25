

public class Computer extends Player { //랜덤만 추가

    public void setRps(){
        int n = (int)(Math.random()*3 + 1); //1~3까지의 랜덤정수
        rps = n;
    }
}
