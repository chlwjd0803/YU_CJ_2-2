import java.util.Scanner;

public class Main{
    public static int max(int[] arr){
        var m = 0;
        //for(int i = 0; i<arr.length; i++) if(arr[i]>m) m=arr[i];
        for (int i : arr) if (i > m) m = i; //for-each 문
        return m;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        var subj = sc.nextInt(); //과목수
        int [] grd = new int[subj];
        for(int i = 0; i < grd.length; i++) grd[i] = sc.nextInt(); //값을 입력할때는 each가 안됨
        var m = max(grd); //과목의 최대점수
        var sum = 0.0;

        //for(int i = 0; i < grd.length; i++) sum += grd[i]/m*100;
        for(int i : grd) sum += (double) i /m*100; //for-each문, 읽어오기만해서 사용가능
        System.out.println(sum/grd.length);
    }
}