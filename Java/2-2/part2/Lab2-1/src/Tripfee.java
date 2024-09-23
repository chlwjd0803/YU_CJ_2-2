import java.util.Scanner;

public class Tripfee {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("여행지 : ");
        String state = sc.nextLine(); //국가 도시 이름
        System.out.print("인원수 : ");
        int person = sc.nextInt(); //인원수
        System.out.print("숙박일 : ");
        int day = sc.nextInt(); //숙박일
        System.out.print("1인당 항공료 : ");
        int air = sc.nextInt(); //항공료
        System.out.print("1방 숙박비 : ");
        int hotel = sc.nextInt(); //숙박비

        int room = (person+1)/2; //방 개수

        System.out.print(person + "명의 "+ state + " " + day + "박" + (day+1) + "일 여행에는 방이 " + room + "개 필요하며");
        System.out.println(" 경비는 " + (person*air + day*room*hotel) + "원 입니다.");
    }
}
