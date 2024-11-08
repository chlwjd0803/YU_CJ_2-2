import java.util.*;

public class CollectionsEx {
    static void printList(LinkedList<String> l){
        Iterator<String> it = l.iterator();
        while(it.hasNext()){
            String e = it.next();
            String separator;
            if(it.hasNext()) //링크할게 있으면 연결
                separator = "->";
            else //없으면 다음줄(링크드리스트가 끝났다는 걸 표시함)
                separator = "\n";
            System.out.print(e + separator);
        }
    }

    public static void main(String[] args) {
        var myList = new LinkedList<String>();

        myList.add("트랜스포머");
        myList.add("스타워즈");
        myList.add("매트릭스");
        myList.add(0, "터미네이터");
        myList.add(2, "아바타");

        Collections.sort(myList);
        printList(myList);

        Collections.reverse(myList);
        printList(myList);

        int index = Collections.binarySearch(myList, "아바타") + 1; //이진탐색
        System.out.println("아바타는 " + index + "번째 요소입니다.");
    }
}