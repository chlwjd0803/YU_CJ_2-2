package app;

import base.Shape;
import derived.Circle;

public class GraphicEditor {
    public static void main(String[] args){
        Shape shape = new Circle();
        //Circle circle = new Circle(); //이 경우엔 base패키지 Shape클래스를 가지고 오지 않아도 된다
        shape.draw();
    }
}
