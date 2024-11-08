public class MyStack {
    public static void main(String[] args){
        var ss = new GStack<String>();
        ss.push("서울");
        ss.push("부산");
        ss.push("시카고");

        for(int i=0; i<3; i++)
            System.out.println(ss.pop());

        var is = new GStack<Integer>();
        is.push(1);
        is.push(3);
        is.push(5);

        for(int i=0; i<3; i++)
            System.out.println(is.pop());
    }
}
