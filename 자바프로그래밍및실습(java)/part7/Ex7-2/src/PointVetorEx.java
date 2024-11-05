import java.util.Vector;

class Point{
    private int x, y;
    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString(){
        return "(" + x + ", " + y + ")";
    }
}

public class PointVetorEx {
    public static void main(String[] args) {
        var v = new Vector<Point>();

        v.add(new Point(1,2));
        v.add(new Point(-5, 20));
        v.add(new Point(30, -8));

        v.remove(1);

        //벡터에 있는 Point 객체 모두 검색하여 출력
        for(var i=0; i<v.size(); i++){
            Point p = v.get(i); // 벡터에서 i 번째 Point 객체 얻어내기
            System.out.println(p); //p.toSrting()을 이용하여 객체 p 출력
        }
    }
}