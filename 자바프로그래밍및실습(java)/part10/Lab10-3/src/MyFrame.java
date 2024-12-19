import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MyFrame extends JFrame {
    private JLabel scoreLabel = new JLabel("점수:0"); //점수표시
    private int score = 0;

    public MyFrame() {
        super("클릭 게임");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(null); //레이아웃 매니저 비활성화
        scoreLabel.setSize(60,20); //점수글자 사이즈
        scoreLabel.setLocation(10,10); //점수판 위치
        c.add(scoreLabel); //추가

        //JLabel label = new JLabel("C");
        ImageIcon imageIcon = new ImageIcon("resource/images/Netflix.png");
        JLabel label = new JLabel(imageIcon); //이미지를 레이블로 추가
        c.add(label); //컴포넌트로 올리기
        label.setLocation(100,100); //레이블의 위치 정해주기
        //label.setSize(20,20);
        label.setSize(imageIcon.getIconWidth(),imageIcon.getIconHeight());

        label.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                JLabel jLabel = (JLabel) e.getSource(); //참조반환
                Container c = jLabel.getParent(); //JLabel의 컨테이너를 참조함
                int xBound = c.getWidth() - jLabel.getWidth();
                int yBound = c.getHeight() - jLabel.getHeight();
                int x = (int)(Math.random() * xBound); //랜덤을 위한 작업들,,,
                int y = (int)(Math.random() * yBound);
                jLabel.setLocation(x, y); //내부적으로 repaint를 자동호출함
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
