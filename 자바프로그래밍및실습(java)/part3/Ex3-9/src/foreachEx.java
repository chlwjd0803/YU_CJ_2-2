public class foreachEx {
    enum Week { 월, 화, 수, 목, 금, 토, 일 }
    //상수집합을 정의하는 특별한 자료형 enum
    // 생소한 개념이니 시험 전에 숙지할것

    public static void main(String[] args) {
        int [] n = { 1,2,3,4,5 }; //자동적으로 5칸의 배열 할당
        String names[] = { "사과", "배", "바나나", "체리", "딸기", "포도" } ;

        int sum = 0;
        // 아래 for-each에서 k는 n[0], n[1], ..., n[4]로 반복
        for (int k : n) {
            System.out.print(k + " "); // 반복되는 k 값 출력
            sum += k;
        }
        System.out.println("합은" + sum);

        // 아래 for-each에서 s는 names[0], names[1], ..., names[5]로 반복
        for (String s : names)
            System.out.print(s + " ");
        System.out.println();

        // 아래 for-each에서 day는 월, 화, 수, 목, 금, 토, 일 값으로 반복
        // 시험 문제로 아래와 같이 생소한 개념을 출제할 수 있음
        for (Week day : Week.values())
            System.out.print(day + "요일 ");
        System.out.println();
    }
}