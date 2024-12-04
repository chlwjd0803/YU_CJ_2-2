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

            String [] tokens = line.split(" "); //String 배열에 이름과 점수 줄줄이 저장
            String name = tokens[0]; //0번째는 이름을 저장함
            Vector<Integer> v = map.get(name); //여기서 해당 학생의 벡터에 점수를 기록하는것
            if(v == null){ //get을 하였는데 해당하는 값이 없을경우
                System.out.println(name + "은 없는 학생입니다.");
                continue;
            }
            //이름이 해시맵에있는 경우 벡터 v에 점수 삽입
            //이미 split을 통해 점수들이 구분되어 있으므로 알아서 들어감
            for(var i=0; i<tokens.length - 1; i++) v.add(Integer.parseInt(tokens[i+1]));
        }

        while(true){
            System.out.print("검색할 이름 : ");
            String name = sc.nextLine();

            if(name.equals("그만")) break;

            Vector<Integer> v = map.get(name); //이름에 맞는 벡터를 가져옴
            if(v == null){
                System.out.println(name + "은 없는 학생입니다.");
                continue;
            }
            if(v.size() == 0){ //벡터가 비었을때
                System.out.println(name + "은 토익 점수가 없습니다.");
                continue;
            }
            for(int score : v){ //for each문을 활용하여 출력
                System.out.print(score + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}