class Shape { // 슈퍼 클래스
    public Shape next;
    public Shape() { next = null; }
    //위는 연결리스트의 개념을 고려하여 작성되었다고 추정
    //Shape객체가 next라는 또다른 객체를 가리킬 수 있다는 뜻. 오버라이딩의 의미
    //없어도 실행됨

    public void draw() {
        System.out.println("Shape");
    }
}

class Line extends Shape {
    public void draw() { // 메소드 오버라이딩
        System.out.println("Line");
    }
}

class Rect extends Shape {
    public void draw() { // 메소드 오버라이딩
        System.out.println("Rect");
    }
}

class Circle extends Shape {
    public void draw() { // 메소드 오버라이딩
        System.out.println("Circle");
    }
}

public class MethodOverridingEx {
    static void paint(Shape p) { //인수로 업캐스팅되었음
        p.draw(); // p가 가리키는 객체 내에 오버라이딩된 draw() 호출.
        // 동적 바인딩
    }

    public static void main(String[] args) {
        Line line = new Line();
        paint(line);
        paint(new Shape());
        paint(new Line());
        paint(new Rect());
        paint(new Circle());
    }
}