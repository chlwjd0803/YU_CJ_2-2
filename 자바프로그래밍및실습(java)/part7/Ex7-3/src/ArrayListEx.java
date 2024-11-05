import java.util.*;

public class ArrayListEx {
    public static void main(String[] args) {
        var a = new ArrayList<String>();

        var sc = new Scanner(System.in);

        for(var i=0; i<4; i++){
            System.out.print("이름을 입력하세요 : ");
            String s = sc.next();
            a.add(s);
        }

        for(var i=0; i<a.size(); i++){
            String name = a.get(i);
            System.out.println(name + " ");
        }


        //length는 get뒤에서 쓸 수 있는것 인지
        int longestIndex = 0;
        for(var i=1; i<a.size(); i++){
            if(a.get(longestIndex).length() < a.get(i).length()){
                longestIndex = i;
            }
        }
        System.out.println("\n가장 긴 이름은 : " + a.get(longestIndex));
        sc.close();
    }
}