public class GenericMethodEx {
    public static <T> GStack<T> reverse(GStack<T> a){
        var s = new GStack<T>();
        while(true){
            T tmp;
            tmp = a.pop();
            if(tmp == null) break;
            else s.push(tmp);
        }
        return s;
    }

    public static void main(String[] args){
        var gs = new GStack<Double>();

        for(int i=0; i<5; i++) gs.push((double)i); // 오토박싱으로 사용
        //gs.push(new Double(i)); // 해당 방식은 삭제됨
        gs = reverse(gs);
        for(int i=0; i<5; i++) System.out.println(gs.pop());
    }
}
