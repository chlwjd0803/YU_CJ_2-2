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
    private JLabel targetLabel; //타겟
    private Thread targetThread; //타겟이 움직이기 위해 스레드 선언

    public GamePanel(){
        setLayout(null);
        baseLabel.setSize(40,40);
        baseLabel.setOpaque(true); //불투명성 on
        baseLabel.setBackground(Color.BLACK); //총 색깔 검정

        ImageIcon icon = new ImageIcon("res/image/target2.png"); //인스타 타겟 이미지
        targetLabel = new JLabel(icon);
        targetLabel.setSize(icon.getIconWidth(),icon.getIconHeight()); //아이콘 원본 사이즈 만큼 맞춰줌

        bulletLabel.setSize(10,10);
        bulletLabel.setOpaque(true); //불투명성 on
        bulletLabel.setBackground(Color.RED); //총알 색상 빨강

        //다 만든 후 추가
        add(baseLabel);
        add(targetLabel);
        add(bulletLabel);
    }

    public void startGame(){
        baseLabel.setLocation(this.getWidth()/2 - baseLabel.getWidth()/2,
                this.getHeight() - baseLabel.getHeight());
        //문제의 검은네모의 위치를 보면 해당식이 나온 것을 알 수 있다.
        bulletLabel.setLocation(this.getWidth()/2 - bulletLabel.getWidth()/2,
                this.getHeight() - baseLabel.getHeight() - bulletLabel.getHeight());
        //빨간점의 위치를 보면 베이스 위에 붙어있으므로 맞게 조절해줌.
        targetLabel.setLocation(0,0);

        targetThread = new TargetThread(targetLabel); //타겟 스레드 할당
        targetThread.start(); //타겟 스레드 활성화 - 시작
        baseLabel.setFocusable(true);
        baseLabel.requestFocus(); //총에다가 포커스를 줌
        baseLabel.addKeyListener(new KeyAdapter() {
            BulletThread bulletThread = null;
            @Override
            public void keyPressed(KeyEvent e) {
                if(e.getKeyChar() == '\n'){ //엔터키를 누른다면, 엔터키는 keyChar에서 \n
                   if(bulletThread == null || !bulletThread.isAlive()){ //총알 스레드가 미작동중, 총알 스레드가 죽음
                       bulletThread = new BulletThread(bulletLabel, targetLabel, targetThread);
                       bulletThread.start();
                       //새로운 스레드 시작, 총알이 다시 움직임. 쏘고나서 재장전한 과정이다.
                   }
                }
            }
        });
    }

    class TargetThread extends Thread{
        private JComponent target;
        public TargetThread(JComponent target){
            this.target = target;
            target.setLocation(0,0); //타겟의 초기위치는 0,0임
            target.getParent().repaint(); //지정이 완료되었으니 다시 그리기

        }

        @Override
        public void run() {
            while(true){
                int x = target.getX() + 5;
                int y = target.getY();
                if(x>GamePanel.this.getWidth()) //화면 밖으로 나가면
                    target.setLocation(0,0); //제자리
                else
                    target.setLocation(x, y); //아니면 계속하여 다음위치로
                target.getParent().repaint(); //지정이 완료되었으니 다시 그리기
                try {
                    sleep(20); //빠른속도로가겠지? 타겟의 속도조절
                } catch (InterruptedException e) {
                    // 타겟이 총알에 맞았을때 인터럽트 발생할 것..
                    target.setLocation(0,0);
                    target.getParent().repaint(); //총에 맞고 처음위치에 다시 그려짐
                    try {
                        sleep(500); //맞고나서 0.5초동안 쉬다가 게임 재시작
                    } catch (InterruptedException ex) {

                    }
                }
            }
        }
    }

    class BulletThread extends Thread{
        private JComponent bullet, target;
        private Thread targetThread;

        //총알 스레드 생성자
        public BulletThread(JComponent bullet, JComponent target, Thread targetThread) {
            this.bullet = bullet;
            this.target = target;
            this.targetThread = targetThread;
        }

        @Override
        public void run(){
            while(true){
                if(hit()){
                    targetThread.interrupt(); //타겟 인터럽트 발생
                    bullet.setLocation(bullet.getParent().getWidth()/2 - bullet.getWidth()/2,
                            bullet.getParent().getHeight() - bullet.getHeight() - 40); //원래 위치로 이동
                    return; //이후 본인 스레드도 종료
                }

                int x = bullet.getX();
                int y = bullet.getY() - 5;
                if(y<0){ //맨 상단까지 올라가면
                    bullet.setLocation(bullet.getParent().getWidth()/2 - bullet.getWidth()/2,
                            bullet.getParent().getHeight() - bullet.getHeight() - 40);
                    bullet.getParent().repaint(); //원위치 후 그림
                    return; //스레드 종료
                }
                bullet.setLocation(x, y); //위치 세팅하고
                bullet.getParent().repaint(); //다시그림
                try {
                    sleep(5); //총알 속도는 매우 빠름
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
        private boolean targetContains(int x, int y){
            if((target.getX() <= x) && (target.getX() + target.getWidth() -1 >= x)
            && (target.getY() <= y) && (target.getY() + target.getHeight() -1 >= y))
                return true;
            else
                return false;
        }
        private boolean hit(){
            int x = bullet.getX();
            int y = bullet.getY();
            int w = bullet.getWidth();
            int h = bullet.getHeight();
            //부딪혔을때의 조건 나올듯
            if(targetContains(x,y) || targetContains(x+w-1, y)
            || targetContains(x, y+h-1) || (targetContains(x+w-1, y+h-1)))
                return true;
            else
                return false;
        }
    }
}
