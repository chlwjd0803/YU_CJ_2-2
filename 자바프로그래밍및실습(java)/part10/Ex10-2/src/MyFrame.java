import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MyFrame extends JFrame {
    private JLabel la = new JLabel("Hello");
    private final int FLYING_UNIT = 35;

    public MyFrame() {
        super("마우스 이벤트");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(null);
        la.setSize(50,20);
        la.setLocation(30,30);
        c.add(la);
        /*
        c.addMouseListener(new MouseListener() { //리스너 인터페이스 이용법
            @Override
            public void mouseClicked(MouseEvent e) {

            }

            @Override
            public void mousePressed(MouseEvent e) {
                la.setLocation(e.getX(),e.getY());
            }

            @Override
            public void mouseReleased(MouseEvent e) {

            }

            @Override
            public void mouseEntered(MouseEvent e) {

            }

            @Override
            public void mouseExited(MouseEvent e) {

            }
        });
        */

        c.addMouseListener(new MouseAdapter() { //어댑터 이용법, 익명클래스방식
            @Override
            public void mousePressed(MouseEvent e) {
                if(e.getButton() == MouseEvent.BUTTON2) //마우스 휠 버튼으로 정지상태에서 가져오기 가능
                    la.setLocation(e.getX(),e.getY());
            }
        });
        c.addMouseMotionListener(new MouseMotionAdapter() { //어댑터 이용(모션, 드래그)
            @Override
            public void mouseDragged(MouseEvent e) {
                la.setLocation(e.getX(),e.getY());
            }
        });
        c.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                int keyCode = e.getKeyCode();
                switch (keyCode){
                    case KeyEvent.VK_UP -> la.setLocation(la.getX(), la.getY()-FLYING_UNIT);
                    case KeyEvent.VK_DOWN -> la.setLocation(la.getX(), la.getY()+FLYING_UNIT);
                    case KeyEvent.VK_LEFT -> la.setLocation(la.getX()-FLYING_UNIT, la.getY());
                    case KeyEvent.VK_RIGHT -> la.setLocation(la.getX()+FLYING_UNIT, la.getY());
                }
            }
        });

        setSize(300,300);
        setVisible(true);
        c.setFocusable(true);
        c.requestFocus();

    }

    public static void main(String[] args) {
        new MyFrame();
    }
}
