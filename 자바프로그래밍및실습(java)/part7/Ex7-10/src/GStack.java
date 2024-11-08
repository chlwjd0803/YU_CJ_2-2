public class GStack<T> { //클래스에 제네릭 타입으로 선언
    int tos;
    Object[] stk;
    //Object로 선언하는이유는
    //제네릭 배열을 생성할 수 없게 java에서 막고있음
    //이를 우회하기위해 모든객체가 상속받는 Object로 선언하는것
    public GStack() {
        tos = 0;
        stk = new Object[10];
    }

    public void push(T item){
        if(tos==10) return;
        stk[tos++]=item;
    }

    public T pop(){
        if(tos==0) return null;
        return (T)stk[--tos]; //다운캐스팅 방식으로 리턴
    }
}
