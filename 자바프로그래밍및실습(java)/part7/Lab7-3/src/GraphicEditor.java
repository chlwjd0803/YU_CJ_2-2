import java.awt.*;
import java.util.Scanner;
import java.util.Vector;

public class GraphicEditor {
    private Scanner sc = new Scanner(System.in);
    private Vector<Shape> v = new Vector<Shape>();

    private void insert(){
        System.out.print("선(1), 사각형(2), 원(3) : ");
        int type = sc.nextInt();
        Shape shape = null;
        switch(type){
            case 1->shape = new Line();
            case 2->shape = new Rect();
            case 3->shape = new Circle();
        }
        if(shape == null){
            System.out.println("잘못된 선택입니다.");
            return;
        }
        else v.add(shape);
    }

    private void delete(){
        System.out.print("삭제할 도형 위치 : ");
        int index = sc.nextInt();
        try {
            v.remove(index);
        } catch(Exception e){ //모든 예외를 그냥 처리해주는 Exception, 슈퍼 클래스
            System.out.println("잘못된 index 접근입니다.");
        }
    }

    private void view(){
        for(Shape s : v){ //for each 활용해보기, 벡터v는 Shape타입을 가지므로
            s.draw();
        }
    }

    public void run(){
        while(true){
            System.out.print("삽입(1) / 삭제(2) / 모두보기(3) / 종료(4) : ");
            int choice = sc.nextInt();
            switch(choice){
                case 1->insert();
                case 2->delete();
                case 3->view();
                case 4->{return;}
                default -> System.out.println("잘못된 선택입니다.");
            }
        }
    }

}
