public class StringStack implements Stack {
    private String [] stack;
    private int top;
    private int len;
    private int cap;

    public StringStack(int cap) {
        stack = new String[cap];
        top = -1;
        this.cap = cap;
    }

    @Override
    public int length() {return top+1;}

    @Override
    public int capacity() {return cap;}

    @Override
    public String pop() {
        return stack[top--]; //그 자리에 것을 반환하고 top 감소함
    }

    @Override
    public boolean push(String val) {
        if(top == cap-1) return false; //용량이 10이면 인덱스는 9까지이므로 비교가 이렇다.
        else{
            stack[++top] = val;
            return true;
        }
    }
}
