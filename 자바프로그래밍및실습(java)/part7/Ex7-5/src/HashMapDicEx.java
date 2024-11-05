import java.util.*;



public class HashMapDicEx {
    public static void main(String[] args) {
        var dic = new HashMap<String, String>();

        dic.put("baby", "아기");
        dic.put("love", "사랑");
        dic.put("apple", "사과");

        var sc = new Scanner(System.in);

        while(true){
            System.out.print("찾고 싶은 단어는?");
            String eng = sc.next();
            if(eng.equals("exit")){ //스트링 객체이므로
                System.out.println("종료하겠습니다");
                break;
            }

            String kor = dic.get(eng); //HashMap을 통한 대응하는 단어 가져옴, 없으면 null
            if(kor == null) System.out.println(eng + "는 없는 단어입니다.");
            else System.out.println(kor);
        }

        sc.close();
    }
}