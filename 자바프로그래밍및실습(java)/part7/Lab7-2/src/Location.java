public class Location {
    String city;
    double latitude; //위도
    double longitude; //경도

    public Location(String city, double latitude, double longitude){
        this.city = city;
        this.latitude = latitude;
        this.longitude = longitude;
    }

    @Override
    public String toString(){
        return city + " " + latitude + " " + longitude;
    }
    //이런걸 콜백 메소드라고 함 : 객체를 그냥 프린트했을때 이게 불려짐
    //이승철 박사님의 말씀
}
