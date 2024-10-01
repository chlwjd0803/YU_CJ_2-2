import java.util.Scanner;
//한글이 되는 IDE에서 작동시킬것
public class DicApp {
    private Scanner sc;
    private Dictionary dic;

    public void run(){
        sc = new Scanner(System.in);
        System.out.println("한영 검색프로그램 입니다.");

        while(true){
            System.out.println("한글단어? ");
            String word = sc.next();
            if(word.equals("그만")) break;
            System.out.println(dic.kor2eng(word));
        }
        System.out.println("종료합니다.");
    }

    public static void main(String[] args) {
        DicApp dic = new DicApp();
        dic.run();
    }
}
