import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {
    private JTextField source = new JTextField(); //텍스트 필드 할당
    private JButton btn = new JButton("계산"); //계산이라는 이름을 표시하고있는 버튼 할당
    private JTextField[] outputTFs = new JTextField[8]; // 텍스트필드 배열(여러개) 할당
    private int[] units = {50000, 10000, 1000, 500, 100, 50, 10, 1}; //숫자로 된 돈
    private String[] nameOfUnits = {"오만원", "만원", "천원", "오백원", "백원", "오십원", "십원", "일원"}; //언어로 된 돈


    public MyFrame(){
        super("금액 환전기"); //setTitle("금액 환전기");
        setDefaultCloseOperation(EXIT_ON_CLOSE); //창이 닫기면 프로그램 종료
        Container contentPane = getContentPane(); //컨텐트 팬 불러오기(아무것도 없으므로 그냥 바로 겟함)
        contentPane.setLayout(new BorderLayout()); //보더 레이아웃 설정

        JPanel inputPanel = new JPanel(new GridLayout(1,3)); //1행 3열짜리 패널 생성 즉 한줄
        inputPanel.add(new JLabel("금액")); //맨 왼쪽에 금액이라는 레이블 생성
        inputPanel.add(source); //입력할 텍스트필드 추가
        inputPanel.add(btn); //누를 계산버튼 추가

        JPanel outputPanel = new JPanel(new GridLayout(8,2)); //8행 2열짜리 패널 생성
        for(int i=0; i<units.length; i++){ //화폐 개수만큼 설정해줌
            outputPanel.add(new JLabel(nameOfUnits[i])); //오만원, 만원, 천원 등 화폐 문장 레이블 추가
            outputTFs[i] = new JTextField(); //텍스트필드 8개 순차할당
            outputTFs[i].setHorizontalAlignment(JTextField.CENTER); //텍스트필드를 중앙으로 위치시킴
            outputPanel.add(outputTFs[i]); //마지막으로 출력패널에 추가함
            //반복문이 끝나고나면 8행2열자리에 텍스트필드가 들어가진 모습을 완성함
        }

        //패널들의 세부작업을 끝내고 컨텐트 팬에다가 추가
        contentPane.add(inputPanel, BorderLayout.NORTH); //입력칸은 상단에 추가
        contentPane.add(outputPanel, BorderLayout.CENTER); //화폐칸은 중간에 추가


        //버튼에 액션리스너 추가
        btn.addActionListener(new ActionListener() { //익명클래스
            @Override
            public void actionPerformed(ActionEvent e) {
                String value = source.getText(); //텍스트 필드 source에 있는 텍스트를 읽어옴
                try{
                    int money = Integer.parseInt(value); //String 형이니까 int형으로 변환
                    int res;
                    for(int i=0; i<units.length; i++){
                        res = money / units[i]; //foreach를 쓰지않는이유
                        outputTFs[i].setText(res+""); //이걸 하기위해.., ""를 입력하면 문자열로 자동 들어감
                        if(res>0){
                            money = money % units[i];
                        }
                    }
                    source.setText(""); //입력값이 없어지는 효과
                } catch (Exception ee){
                    source.setText(""); //잘못된 입력이면 사라짐
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
