import java.io.*;
import java.util.Scanner;

public class Lab81 {
    public static void main(String[] args) {
        //원래 백슬레시로 표기하나 \는 한번만 하면 제거해버리므로 \\가 \임
        //그래서 파일명을 입력할때 /도 \로 인정해줌

        var file = new File("c:\\windows\\system.ini");
        //var file = new File("c:/windows/system.ini"); //이것도 가능
        System.out.println(file.getPath() + " 읽기"); //출력할때 경로명은 윈도우식으로 정확히 표기해줌

        try{
            var fsc = new Scanner(new FileReader(file)); //이 형태 주목하기, 파일을 읽어오는 방식
            int lineNumber = 1;
            while(fsc.hasNext()){ //스캐너에서 지원하는 메소드, 파일에서 유용하게 hasNext사용가능
                String line = fsc.nextLine(); //라인으로 읽어옴
                System.out.printf("%4d : %s\n", lineNumber++, line);
            }
            fsc.close();
        } catch (FileNotFoundException e) {
            System.out.println(file.getName() + " 없음.");
        }
    }
}
