import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MyFrame extends JFrame {

    public MyFrame(){
        super("Moving String..");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        JLabel java = new JLabel("Love Java");
        c.add(java);
        java.addKeyListener(new KeyAdapter(){
            @Override
            public void keyPressed(KeyEvent e) {
                if(e.getKeyCode() == KeyEvent.VK_LEFT){ //왼쪽을 입력하면
                    JLabel jLabel = (JLabel)e.getSource();
                    String text = jLabel.getText();
                    String first = text.substring(0,1); //하나만 잘라 가져옴
                    String remain = text.substring(1); //1번째부터 끝까지
                    jLabel.setText(remain+first);
                } else if(e.getKeyCode() == KeyEvent.VK_RIGHT){
                    JLabel jLabel = (JLabel)e.getSource();
                    String text = jLabel.getText();
                    String last = text.substring(text.length()-1); //마지막 인덱스만 가져옴
                    String remain = text.substring(0, text.length()-1); //0번째부터 i-1번째까지
                    jLabel.setText(last+remain);
                }
            }
        });
        setSize(250,200);
        setVisible(true);
        java.setFocusable(true);
        java.requestFocus();

    }

    public static void main(String[] args) {
        new MyFrame();
    }
}
