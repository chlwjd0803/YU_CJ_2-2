import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;

//앞 예제보다 확장됨.. 이것만 볼것
public class MyFrame extends JFrame {

    private void sizeUp(JLabel label){
        Font f = label.getFont();
        int size = f.getSize();
        label.setFont(new Font(f.getFontName(), f.getStyle(), size+5));
    }

    private void sizeDown(JLabel label){
        Font f = label.getFont();
        int size = f.getSize();
        if(size-5 < 5) return; //사이즈가 5보다는 더 작아지면 안됨
        label.setFont(new Font(f.getFontName(), f.getStyle(), size-5));
    }

    public MyFrame(){
        super("Moving String..");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        JLabel java = new JLabel("Love Java");
        c.add(java);
        java.setFont(new Font("Cooper Black", Font.ITALIC, 15));


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
                } else if(e.getKeyChar() == '+' || e.getKeyCode() == KeyEvent.VK_UP){
                    sizeUp((JLabel) e.getSource());
                } else if(e.getKeyChar() == '-' || e.getKeyCode() == KeyEvent.VK_DOWN){
                    sizeDown((JLabel) e.getSource());
                }
            }
        });


        java.addMouseWheelListener(new MouseWheelListener() {
            @Override
            public void mouseWheelMoved(MouseWheelEvent e) {
                int n = e.getWheelRotation();
                if(n < 0){
                    sizeDown((JLabel) e.getSource());
                }
                else{
                    sizeUp((JLabel) e.getSource());
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
