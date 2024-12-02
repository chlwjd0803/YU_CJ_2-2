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
        c.add(new JScrollPane(ta), BorderLayout.CENTER);
        c.add(slider, BorderLayout.SOUTH);

        slider.setMajorTickSpacing(20); //큰묶음은 20간격
        slider.setMinorTickSpacing(5); //작은건 5간격
        slider.setPaintLabels(true);
        slider.setPaintTicks(true);

        ta.addKeyListener(new KeyAdapter(){
            @Override
            public void keyTyped(KeyEvent e) {
                JTextArea textArea = (JTextArea) e.getSource();
                int size = textArea.getText().length();

                if(size >= 100) {
                    size = 100;
                    try {
                        textArea.setText(textArea.getText(0,100));
                    } catch (BadLocationException ex) {}
                }
                slider.setValue(size);
            }
        });
        slider.addChangeListener(new ChangeListener(){
            @Override
            public void stateChanged(ChangeEvent e) {
                JSlider jSlider = (JSlider) e.getSource();
                if(ta.getText().length() <= jSlider.getValue())
                    jSlider.setValue(ta.getText().length());
                else {
                    try {
                        ta.setText(ta.getText(0, jSlider.getValue()));
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
