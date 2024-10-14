public class Circle {
    private int radius;
    private String name; //접근 지정자가 private
    // 접근지정자 단원에서 더 심도있게 볼것

    private Circle(){}
    //????

    private double getArea(){return 3.14 * radius * radius;}
    // 이것도 접근지정자 private임.

    public static void main(String[] args){
        Circle pizza = new Circle();
        pizza.radius = 10;
        pizza.name = "자바피자";
        double area = pizza.getArea();
        System.out.println(pizza.name + "의 면적은 " + area);

        Circle donut = new Circle();
        donut.radius = 2;
        donut.name = "자바도넛";
        area = donut.getArea();
        System.out.println(donut.name + "의 면적은 " + area);
    }
}
