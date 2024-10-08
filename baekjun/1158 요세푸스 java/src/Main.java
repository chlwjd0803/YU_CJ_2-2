import java.util.Scanner;

//%연산자 이용
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        var n = sc.nextInt(); //총 인원수
        var k = sc.nextInt(); //제거 위치
        int [] person = new int[n]; //사람 줄
        int [] result = new int[n]; //결과 출력용
        for(int i = 0; i < n; i++) person[i] = i+1; //1번부터 n번까지 지정

        var pos = 0;
        var resn = 0;
        int [] nextper = new int[n-resn];
        while(resn < n){
            if(pos == n) pos = 0; //칸을 넘어갈경우 0으로 돌아감
            if((pos+1)%k == 0){ //인덱스와 1값 차이남
                result[resn++] = person[pos];
            }
        }
    }
}