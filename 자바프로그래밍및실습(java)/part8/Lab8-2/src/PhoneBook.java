import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.HashMap;
import java.util.Scanner;

public class PhoneBook {
    private File filename = new File("c:/temp/phone.txt");
    private HashMap<String, String> phoneBook = new HashMap<String, String>();

    public PhoneBook() {}
    public PhoneBook(File filename) {this.filename = filename;}

    private void readPhoneFile(){
        try{
            var fs = new Scanner(new FileReader(filename));
            while(fs.hasNext()){
                String name = fs.next();
                String tel = fs.next();
                phoneBook.put(name, tel); //띄어쓰기가 번호에 없을 경우 가정함
            }
            fs.close();
            System.out.println("총 " + phoneBook.size() + "개 읽음");
        } catch (FileNotFoundException e) {
            System.out.println(filename.getName() + "없음.");
        }
    }
    private void search(){
        Scanner sc = new Scanner(System.in); //표준입력
        while(true){
            System.out.print("이름 : ");
            String name = sc.next();
            if(name.equals("그만")) return;
            String tel = phoneBook.get(name);
            if(tel == null) System.out.println(name + "은 없음");
            else System.out.println(name + " : " + tel);
        }
    }

    public void run(){
        readPhoneFile();
        search();
        System.out.println("종료합니다.");
    }

}