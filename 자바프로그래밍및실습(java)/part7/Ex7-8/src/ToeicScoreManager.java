import java.util.*;


// 활용하는 범위가 넓어서 시험공부할 때 좋음
public class ToeicScoreManager {
    public static void main(String[] args) {
        //학생 이름과 토익 점수를 저장할 해시맵 생성(성적들을 Vector에 저장)
        var map = new HashMap<String, Vector<Integer>>();
        var sc = new Scanner(System.in);

        map.put("한지운", new Vector<Integer>());
        map.put("김하진", new Vector<Integer>());
        map.put("하여린", new Vector<Integer>());
        map.put("윤단비", new Vector<Integer>());

        System.out.println("등록된 학생 : 한지운, 김하진, 하여린, 윤단비 등 4명입니다");

        while(true){
            System.out.print("이름과 점수들 : ");
            String line = sc.nextLine(); // 한 라인 입력 예 : 윤단비 400 500 550
            if(line.equals("그만")) break;

            String [] tokens = line.split(" ");
            String name = tokens[0];
            Vector<Integer> v = map.get(name);
            if(v == null){ //get을 하였는데 해당하는 값이 없을경우
                System.out.println(name + "은 없는 학생입니다.");
                continue;
            }
            //이름이 해시맵에있는 경우 벡터 v에 점수 삽입
            for(var i=0; i<tokens.length - 1; i++) v.add(Integer.parseInt(tokens[i]));
        }

        while(true){
            System.out.print("검색할 이름 : ");
            String name = sc.nextLine();

            if(name.equals("그만")) break;

            Vector<Integer> v = map.get(name);
            if(v == null){
                System.out.println(name + "은 없는 학생입니다.");
                continue;
            }
            if(v.size() == 0){
                System.out.println(name + "은 토익 점수가 없습니다.");
                continue;
            }
            for(int score : v){
                System.out.print(score + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}