import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MyFrame extends JFrame {
    private JLabel scoreLabel = new JLabel("점수:0");
    private int score = 0;

    public MyFrame() {
        super("클릭 게임");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(null); //레이아웃 매니저 비활성화
        scoreLabel.setSize(60,20);
        scoreLabel.setLocation(10,10);
        c.add(scoreLabel);

        //JLabel label = new JLabel("C");
        ImageIcon imageIcon = new ImageIcon("resource/images/Netflix.png");
        JLabel label = new JLabel(imageIcon);
        c.add(label);
        label.setLocation(100,100);
        //label.setSize(20,20);
        label.setSize(imageIcon.getIconWidth(),imageIcon.getIconHeight());
        label.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                JLabel jLabel = (JLabel) e.getSource();
                Container c = jLabel.getParent(); //부모객체반환??
                int xBound = c.getWidth() - jLabel.getWidth();
                int yBound = c.getHeight() - jLabel.getHeight();
                int x = (int)(Math.random() * xBound);
                int y = (int)(Math.random() * yBound);
                jLabel.setLocation(x, y);
                score += 10;
                scoreLabel.setText("점수:"+score);
            }
        });
        setSize(300, 300);
        setVisible(true);

    }

    public static void main(String[] args) {
        new MyFrame();
    }
}
