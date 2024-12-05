import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MyFrame extends JFrame {

    class MyPanel extends JPanel implements Runnable {
        private int x = 100;
        private int y = 100;

        public MyPanel() {
            this.addMouseListener(new MouseAdapter() {
                private Thread th = null;

                @Override
                public void mousePressed(MouseEvent e) {
                    if(th == null){
                        th = new Thread(MyPanel.this);
                        th.start();
                    }
                }
            });
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(Color.CYAN);
            //g.drawOval(x,y,50,50); // 테두리만 그리기
            g.fillOval(x,y,50,50); // 그린 후 채우기
        }

        //runnable을 부르면 이렇게 됨
        @Override
        public void run() {
            while(true){
                try {
                    Thread.sleep(400);
                } catch (InterruptedException e) {}
                x = (int)(Math.random()*this.getWidth());
                y = (int)(Math.random()*this.getHeight()); //자신의 높이 안에서
                repaint();
            }
        }
    }

    public MyFrame(){
        super("랜덤 패널");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setContentPane(new MyPanel());
        setSize(250, 250);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        c.add(new JLabel("쓰레드테스트"));
        setVisible(true);
    }

    public static void main(String[] args) {
        new MyFrame();
    }
}
