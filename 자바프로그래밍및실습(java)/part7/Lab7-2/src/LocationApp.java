import java.util.*;

public class LocationApp {
    private Scanner sc = new Scanner(System.in);
    private HashMap<String, Location> cities = new HashMap<String, Location>();

    private void input(){
        System.out.println("도시,위도,경도를 입력하세요.");
        for(int i=0; i<4; i++){
            String info = sc.nextLine();
            StringTokenizer st = new StringTokenizer(info, ","); //안나올지도,
            String city = st.nextToken().trim(); //토큰을 잘라서 빈칸을 없앰
            double latitude = Double.parseDouble(st.nextToken().trim()); //String형을 double형으로 변경
            double longitude = Double.parseDouble(st.nextToken().trim());
            cities.put(city, new Location(city, latitude, longitude));
        }
    }

    private void printAll(){
        var keys = cities.keySet(); //KeySet()는 Map 인터페이스에 존재함, 외워두기
        //밑의 형식이 출제 가능성이 높음
        //Set<String> keys = cities.keySet(); 이 원형임, 형태 알아놓기
        var it = keys.iterator();
        //Iterator<String> it = keys.iterator();
        System.out.println("----------------------");
        while(it.hasNext()){ //다음이 있다면
            String key = it.next();
            Location loc = cities.get(key); //도시이름 String에 해당하는 Location 객체 호출
            System.out.println(loc); //Location 객체의 내용 출력, 오버라이딩 통한 출력
            //toString 오버라이딩 함수에 의해 출력이 정형화됨
        }
        System.out.println("----------------------");
    }

    private void search(){
        while(true){
            System.out.print("도시명 : ");
            String city = sc.nextLine();
            if(city.equals("exit")) break;
            Location loc = cities.get(city); //키(String)값에 맞는 Location객체 가져옴
            if(loc == null){
                System.out.println(city + "는 없음.");
            } else{
                System.out.println(loc);
            }
        }
    }

    public void run(){
        input();
        printAll();
        search();
    }

}
