import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.text.BadLocationException;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MyFrame extends JFrame {
    private JTextArea ta = new JTextArea(5,10);
    private JSlider slider = new JSlider(0,100,0);

    public MyFrame(){
        super("TextArea 실습");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.add(new JScrollPane(ta), BorderLayout.CENTER); //텍스트구역에 대한 스크롤 팬 적용, 중앙 위치
        c.add(slider, BorderLayout.SOUTH); //슬라이더는 남쪽에 배치

        slider.setMajorTickSpacing(20); //큰묶음은 20간격
        slider.setMinorTickSpacing(5); //작은건 5간격, 눈금자
        slider.setPaintLabels(true); //숫자 레이블 보이기
        slider.setPaintTicks(true); //눈금 보이기

        ta.addKeyListener(new KeyAdapter(){ //키보드 조작에 의한 리스너
            @Override
            public void keyTyped(KeyEvent e) {
                JTextArea textArea = (JTextArea) e.getSource(); //참조로 받음
                int size = textArea.getText().length();

                if(size >= 100) { //사이즈가 100을 못넘게 하는것
                    size = 100;
                    try {
                        textArea.setText(textArea.getText(0,100));
                    } catch (BadLocationException ex) {}
                }
                slider.setValue(size); //슬라이더의 값 증감
            }
        });
        slider.addChangeListener(new ChangeListener(){ //슬라이더 조작에 의한 리스너
            @Override
            public void stateChanged(ChangeEvent e) {
                JSlider jSlider = (JSlider) e.getSource(); //슬라이더가 변화하고 값을 읽어옴
                if(ta.getText().length() <= jSlider.getValue()) //텍스트보다 슬라이더가 길면
                    jSlider.setValue(ta.getText().length()); //슬라이더를 텍스트 길이와 동기화
                else { //아니면
                    try {
                        ta.setText(ta.getText(0, jSlider.getValue())); //슬라이더에 최신화하여 기존에 문자 없앰
                    } catch (BadLocationException ex) {}
                }
            }
        });
        setSize(300,300);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MyFrame();
    }
}
