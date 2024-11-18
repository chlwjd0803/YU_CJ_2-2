import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame{
    public MyFrame(){
        setTitle("첫번째 GUI 프로그램");

        setDefaultCloseOperation(EXIT_ON_CLOSE); //창을 닫았을때 프로그램까지 멈추게함

        Container contentPane = getContentPane();
        contentPane.setBackground(Color.GRAY);
        //contentPane.setLayout(new FlowLayout(FlowLayout.LEFT, 30, 40)); //  플로우방식
        contentPane.setLayout(new BorderLayout()); //보더방식

        //보더방식 추가(없애면 그냥 플로우)
        contentPane.add(new JButton("OK"), BorderLayout.CENTER);
        contentPane.add(new JButton("취소"), BorderLayout.NORTH);
        contentPane.add(new JButton("무시"), BorderLayout.SOUTH);


        setSize(300, 300); //창크기
        setVisible(true); //화면이 보이게
    }

    public static void main(String[] args){
        new MyFrame(); //객체만 만들어줌
        //메인 메소드는 종료되지만 GUI는 끝나지않음
    }
}
