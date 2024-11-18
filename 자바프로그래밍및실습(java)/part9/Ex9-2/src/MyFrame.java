import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame{
    public MyFrame(){
        super("두번째 GUI");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container container = getContentPane();
        container.setLayout(null);
        JLabel la = new JLabel("안녕!!! 자바 스윙!");
        la.setLocation(130, 50);
        la.setSize(250, 20);
        container.add(la);
        for(int i=1; i<=9; i++){
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
