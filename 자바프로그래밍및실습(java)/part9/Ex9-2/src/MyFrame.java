import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame{
    public MyFrame(){
        super("두번째 GUI"); //setTitle과 같음
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        Container container = getContentPane();
        container.setLayout(null); //레이아웃 매니저를 쓰지않고 절대위치로 하겠다는 선언(기출)

        //레이블을 만들고 절대위치와 크기를 지정하는 과정
        JLabel la = new JLabel("안녕!!! 자바 스윙!");
        la.setLocation(130, 50);
        la.setSize(250, 20);
        container.add(la);


        for(int i=1; i<=9; i++){
            //버튼을 만들고 절대위치와 크기를 지정하는 과정
            JButton b = new JButton(i+"");
            b.setLocation(i*15, i*15);
            b.setSize(50, 20);
            container.add(b);
        }
        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args){
        new MyFrame();
    }
}
