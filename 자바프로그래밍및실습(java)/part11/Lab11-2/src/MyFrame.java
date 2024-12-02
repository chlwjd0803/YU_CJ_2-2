import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {
    private JTextField source = new JTextField();
    private JButton btn = new JButton("계산");
    private JTextField[] outputTFs = new JTextField[8];
    private int[] units = {50000, 10000, 1000, 500, 100, 50, 10, 1};
    private String[] nameOfUnits = {"오만원", "만원", "천원", "오백원", "백원", "오십원", "십원", "일원"};

    private JCheckBox[] checkBoxes = new JCheckBox[8];


    public MyFrame(){
        super("금액 환전기");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container contentPane = getContentPane();
        contentPane.setLayout(new BorderLayout());

        JPanel inputPanel = new JPanel(new GridLayout(1,3));
        inputPanel.add(new JLabel("금액"));
        inputPanel.add(source);
        inputPanel.add(btn);

        JPanel outputPanel = new JPanel(new GridLayout(8,3));
        for(int i=0; i<units.length; i++){
            outputPanel.add(new JLabel(nameOfUnits[i]));
            outputTFs[i] = new JTextField();
            outputTFs[i].setHorizontalAlignment(JTextField.CENTER);
            outputPanel.add(outputTFs[i]);
            //반복문이 끝나고나면 8행2열자리에 텍스트가 들어가진 모습을 완성함
            checkBoxes[i] = new JCheckBox();
            checkBoxes[i].setSelected(true); //체크가 되어있는 상태로 시작하는 것
            outputPanel.add(checkBoxes[i]);
        }
        checkBoxes[7].setVisible(false); //1원은 무조건 계산해야하므로.. 체크박스를 건드리지 못하게함, 초기값에의해 true상태

        contentPane.add(inputPanel, BorderLayout.NORTH);
        contentPane.add(outputPanel, BorderLayout.CENTER);

        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String value = source.getText();
                try{
                    int money = Integer.parseInt(value);
                    int res;
                    for(int i=0; i<units.length; i++){
                        if(!checkBoxes[i].isSelected()){
                            outputTFs[i].setText("0");
                            continue; //체크박스가 풀려있으면 포함하지 않는 조건
                        }
                        res = money / units[i]; //foreach를 쓰지않는이유
                        outputTFs[i].setText(res+""); //이걸 하기위해..
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
