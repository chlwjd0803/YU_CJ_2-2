import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MyFrame extends JFrame {
    public MyFrame() {
        super("사격 게임");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        GamePanel gamePanel = new GamePanel();
        setContentPane(gamePanel);
        setSize(300,300);
        setResizable(false); //기본은 true인데 이걸 false하면 실행 후 프레임 크기를 조정할 수 없다.
        setVisible(true);
        gamePanel.startGame();

    }

    public static void main(String[] args) {
        new MyFrame();
    }
}

class GamePanel extends JPanel{
    private JLabel baseLabel = new JLabel(); //발사대 이미지를 넣을 예정
    private JLabel bulletLabel = new JLabel(); //총알
    private JLabel targetLabel;
    private Thread targetThread;

    public GamePanel(){
        setLayout(null);
        baseLabel.setSize(40,40);
        baseLabel.setOpaque(true);
        baseLabel.setBackground(Color.BLACK);

        ImageIcon icon = new ImageIcon("res/image/target2.png");
        targetLabel = new JLabel(icon);
        targetLabel.setSize(icon.getIconWidth(),icon.getIconHeight());

        bulletLabel.setSize(10,10);
        bulletLabel.setOpaque(true);
        bulletLabel.setBackground(Color.RED);

        add(baseLabel);
        add(targetLabel);
        add(bulletLabel);
    }

    public void startGame(){
        baseLabel.setLocation(this.getWidth()/2 - baseLabel.getWidth()/2,
                this.getHeight() - baseLabel.getHeight());
        //문제의 검은네모의 위치를 보면 해당식이 나온 것을 알 수 있다.
        bulletLabel.setLocation(this.getWidth()/2 - bulletLabel.getWidth()/2,
                this.getHeight() - bulletLabel.getHeight() - bulletLabel.getHeight());
        //빨간점의 위치를 보면 베이스 위에 붙어있으므로 맞게 조절해줌.
        targetLabel.setLocation(0,0);

        targetThread = new TargetThread(targetLabel);
        targetThread.start();
        baseLabel.setFocusable(true);
        baseLabel.requestFocus();
        baseLabel.addKeyListener(new KeyAdapter() {
            BulletThread bulletThread = null;
            @Override
            public void keyPressed(KeyEvent e) {
                if(e.getKeyChar() == '\n'){
                   if(bulletThread == null || !bulletThread.isAlive()){
                       bulletThread = new BulletThread(bulletLabel, targetLabel, targetThread);
                       bulletThread.start();
                   }
                }
            }
        });
    }

    class TargetThread extends Thread{
        private JComponent target;
        public TargetThread(JComponent target){
            this.target = target;
            target.setLocation(0,0);
            target.getParent().repaint();

        }

        @Override
        public void run() {
            while(true){
                int x = target.getX() + 5;
                int y = target.getY();
                if(x>GamePanel.this.getWidth())
                    target.setLocation(0,0);
                else
                    target.setLocation(x, y);
                target.getParent().repaint();
                try {
                    sleep(20);
                } catch (InterruptedException e) {
                    // 타겟이 총알에 맞았을때 인터럽트 발생할 것..
                    target.setLocation(0,0);
                    target.getParent().repaint();
                    try {
                        sleep(500);
                    } catch (InterruptedException ex) {

                    }
                }
            }
        }
    }

    class BulletThread extends Thread{
        private JComponent bullet, target;
        private Thread targetThread;

        public BulletThread(JComponent bullet, JComponent target, Thread targetThread) {
            this.bullet = bullet;
            this.target = target;
            this.targetThread = targetThread;
        }

        @Override
        public void run(){
            while(true){
                if(hit()){
                    targetThread.interrupt();
                    bullet.setLocation(bullet.getParent().getWidth()/2 - bullet.getWidth()/2,
                            bullet.getParent().getHeight() - bullet.getHeight() - 40);
                    return; //스레드 종료
                }

                int x = bullet.getX();
                int y = bullet.getY() - 5;
                if(y<0){
                    bullet.setLocation(bullet.getParent().getWidth()/2 - bullet.getWidth()/2,
                            bullet.getParent().getHeight() - bullet.getHeight() - 40);
                    bullet.getParent().repaint();
                    return; //스레드 종료
                }
                bullet.setLocation(x, y);
                bullet.getParent().repaint();
                try {
                    sleep(5);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
        private boolean targetContains(int x, int y){
            if((target.getX() <= x) && (target.getX() + target.getWidth() -1 >= x)
            && (target.getY() <= y) && (target.getY()+target.getHeight() -1 >= y))
                return true;
            else
                return false;
        }
        private boolean hit(){
            int x = bullet.getX();
            int y = bullet.getY();
            int w = bullet.getWidth();
            int h = bullet.getHeight();
            if(targetContains(x,y) || targetContains(x+w-1, y)
            || targetContains(x, y+h-1) || (targetContains(x+w-1, y+h-1)))
                return true;
            else
                return false;
        }
    }
}
