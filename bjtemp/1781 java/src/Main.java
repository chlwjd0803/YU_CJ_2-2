import java.util.Scanner;
import java.util.HashMap; //쓸까 고민중

public class Main {

    public static void sort(int [][] arr, int size){

    }


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        var ddline = 1; //문제를 하나 풀면 데드라인이 하나 증가함
        var sum = 0; //컵라면의 합

        var hw = sc.nextInt(); //숙제의 개수를 입력받음, 즉 배열의 크기가 됨
        int [][] arr = new int[hw][2]; //데드라인과 컵라면수를 저장하기 위함
        int [] dterms = new int[hw]; //각 데드라인이 몇번 출현했나
        int [] startPos = new int[hw]; //입력받는 순간 정렬하기 위함

        //시간 복잡도를 줄이기 위해 공간복잡도를 조금 올림
        for(int i=0; i<hw; i++){
            arr[i][0] = sc.nextInt(); // 데드라인 입력
            arr[i][1] = sc.nextInt(); // 컵라면의 수 입력
            dterms[arr[i][0]]++; //데드라인이 입력되면 횟수을 셈
        }

        for(int i=1; i<hw; i++) startPos[i] = dterms[i-1] + startPos[i-1];

        int [][] temp = new int[hw][2];
        for(int i=0; i<hw; i++){
            temp[startPos[arr[i][0]]++][0] = arr[i][0];
            temp[startPos[arr[i][0]]++][1] = arr[i][1];
        }
        arr = temp; //기존 arr 가비지 생성




        boolean flag = true;
        while(flag) {
            var temp = 0;
            flag = false;
            for (int i = 0; i < hw; i++){
                if ((arr[i][0] == ddline) && (temp < arr[i][1])) {
                    temp = arr[i][1];
                }
            }

            sum += temp; //최대 컵라면 개수를 더함
            ddline++;
        }

        //System.out.println();
        System.out.print(sum);
        sc.close();
    }

}
