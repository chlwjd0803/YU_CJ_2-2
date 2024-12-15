import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MyFrame extends JFrame {

    class MyPanel extends JPanel implements Runnable {
        private int x = 100;
        private int y = 100;

        public MyPanel() { //생성자에서 마우스리스너를 등록해주는 과정
            this.addMouseListener(new MouseAdapter() {
                private Thread th = null;

                @Override
                public void mousePressed(MouseEvent e) {
                    if(th == null){
                        th = new Thread(MyPanel.this);
                        th.start();
                    }
                    else{
                        th.interrupt();
                        th = null;
                    }
                }
            });
        }

        @Override
        protected void paintComponent(Graphics g) { //그래픽
            super.paintComponent(g); //이코드는 그래픽에 필수로 들어가있어야함
            g.setColor(Color.CYAN); //색깔 지정
            //g.drawOval(x,y,50,50); // 테두리만 그리기
            g.fillOval(x,y,50,50); // 그린 후 채우기
        }

        //runnable을 부르면 이렇게 됨
        @Override
        public void run() {
            while(true){
                try {
                    Thread.sleep(400);
                } catch (InterruptedException e) { return; } //종료할 수 있게 인터럽트예외처리 해야함
                x = (int)(Math.random()*this.getWidth()); //시험출제가능 ****************************
                y = (int)(Math.random()*this.getHeight()); //자신의 높이 안에서
                repaint(); //변경하고 다시 그려야함, 좌표가 바뀌었기 때문에
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
