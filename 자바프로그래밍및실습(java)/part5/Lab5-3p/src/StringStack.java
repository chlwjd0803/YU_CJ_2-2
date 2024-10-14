public class StringStack implements Stack  {

    private String [] elements;
    private int tos; //top of stack, 그냥 top으로 사용해도됨


    public StringStack(int capacity) {
        elements = new String[capacity];
        tos = 0; //0으로 시작하는 조건으로 해보는 교수님, 내 코드랑 차이가 있음
    }

    @Override
    public int length() {return tos;} //tos의 값과 개수는 같을것이다.

    @Override
    public int capacity() {return elements.length;} //length 활용

    @Override
    public String pop() {
        if(tos==0) return null; //?
        return elements[--tos];
    }

    @Override
    public boolean push(String val) {
        //stack full?
        if(tos == elements.length){
            return false;
        }
        else{
            elements[tos++] = val;
            return true;
        }
    }
}
