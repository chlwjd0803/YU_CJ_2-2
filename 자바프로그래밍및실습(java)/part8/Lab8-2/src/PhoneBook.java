import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.HashMap;
import java.util.Scanner;

public class PhoneBook {
    private File filename = new File("C:/Temp/phone.txt");
    private HashMap<String, String> phoneBook = new HashMap<>();

    public PhoneBook(File filename) {
        this.filename = filename;
    } //정해둔 쟤 마로 다른 파일로 하고 싶을 수도 있으니까

    public PhoneBook() {}; //원래 기본 생성자에 File이랑 HashMap 만들면 되긴 함

    // 파일 읽어오기 (= phoneBook 만들기)
    private void readPhoneFile(){
        try {
            Scanner fs = new Scanner(new FileReader(filename));
            while(fs.hasNext()){
                //파일은 끝나면 굳이 대기할 필요가 없으니까 있는지 확인하고 가져오는 거임
                //표준 입출력은 끝나면 계속 대기하고 있음
                String name = fs.next(); //띄어쓰기 전까지 가져옴
                String tel = fs.next();
                phoneBook.put(name,tel);
            }
            fs.close();
            System.out.println("총 "+phoneBook.size()+"개 읽음");
            //몇 개인지는 사이즈 보면 알 수 있음
        }
        catch (FileNotFoundException e){
            System.out.println(filename.getName() + "없음");
        }
    }

    // 검색하기
    private void search(){
        Scanner scanner= new Scanner(System.in);
        while(true){
            System.out.print("이름>>");
            String name = scanner.next();
            if(name.equals("exit")) break;
            String tel = phoneBook.get(name);
            if(tel == null) System.out.println(name+"은 없음");
            else System.out.println(name+": "+tel);
        }
    }

    //
    public void run(){
        readPhoneFile();
        search();
    }
}
