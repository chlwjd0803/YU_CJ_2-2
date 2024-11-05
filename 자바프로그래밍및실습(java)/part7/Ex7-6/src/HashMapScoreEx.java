import java.util.*;

public class HashMapScoreEx {
    public static void main(String[] args) {
        var javaScore = new HashMap<String, Integer>();

        //5개의 점수 저장
        javaScore.put("김은비", 97);
        javaScore.put("하여린", 88);
        javaScore.put("전아린", 98);
        javaScore.put("이동건", 70);
        javaScore.put("양승연", 99);

        System.out.println("HashMap의 요소 개수 : " + javaScore.size());

        Set<String> keys = javaScore.keySet(); //HashMap의 키를 얻기 위해 사용됨

        Iterator<String> it = keys.iterator(); //이를 이터레이터를 통해 요소들을 사용하기 위함

        while (it.hasNext()) {
            String name = it.next();
            int score = javaScore.get(name);
            System.out.println(name + " : " + score);
        }
    }
}