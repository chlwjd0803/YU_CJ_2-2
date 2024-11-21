import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/*
class MyActionListner implements ActionListener { //독립 클래스로 작성하는 방법

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton btn = (JButton) e.getSource();
        if(btn.getText().equals("Action"))
            btn.setText("액션");
        else
            btn.setText("Action");
    }

}
*/

public class MyFrame extends JFrame {
    /*
    private class MyActionListner implements ActionListener { //내부 클래스로 작성하는 방법

        @Override
        public void actionPerformed(ActionEvent e) {
            JButton btn = (JButton) e.getSource();
            if(btn.getText().equals("Action")){
                btn.setText("액션");
                setTitle("액션");
            } else {
                btn.setText("Action");
                setTitle("Action");
            }
        }

    }
    */

    public MyFrame() {
        super("이벤트 리스너 예제");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());

        JButton btn = new JButton("Action");
        //btn.addActionListener(new MyActionListner());

        btn.addActionListener(new ActionListener() { //내부 클래스로 작성하는 방법

            @Override
            public void actionPerformed(ActionEvent e) {
                JButton btn = (JButton) e.getSource();
                if(btn.getText().equals("Action")){
                    btn.setText("액션");
                    setTitle("액션");
                } else {
                    btn.setText("Action");
                    setTitle("Action");
                }
            }

        });
        
        c.add(btn);

        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MyFrame();
    }
}
