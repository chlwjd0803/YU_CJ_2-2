import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class MyFrame extends JFrame {
    private JLabel[] keyMsgs;

    public MyFrame(){
        super("키 이벤트");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        keyMsgs = new JLabel[3];
        keyMsgs[0] = new JLabel("getKeyCode");
        keyMsgs[1] = new JLabel("getKeyChar");
        keyMsgs[2] = new JLabel("getKeyText");
        for(JLabel l : keyMsgs)
            c.add(l);
        setSize(300, 300);
        setVisible(true);
        c.setFocusable(true);
        c.requestFocus();
        c.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                int keyCode = e.getKeyCode();
                char keyChar = e.getKeyChar();
                keyMsgs[0].setText(keyCode+""); //문자열로 바꿔주기 위함
                keyMsgs[1].setText(keyChar+"");
                keyMsgs[2].setText(KeyEvent.getKeyText(keyCode));
                if(keyCode == KeyEvent.VK_F1){
                    c.setBackground(Color.RED);
                }
                if(keyCode == KeyEvent.VK_F2){ //else를 붙일 필요가 있을까
                    c.setBackground(Color.GREEN);
                }
                if(keyCode == KeyEvent.VK_F3){
                    c.setBackground(Color.BLUE);
                }

            }
        });
    }

    public static void main(String[] args){
        new MyFrame();
    }

}
