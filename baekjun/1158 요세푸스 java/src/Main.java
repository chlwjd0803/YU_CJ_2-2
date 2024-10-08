import java.util.Scanner;

class Queue{
    private int [] arr; //사람 수
    private int head;
    private int tail;
    public int size;

    public Queue(int n){
        size = n*2; //하나를 제거 후 뒤로 다 넘기므로 2배 용량이면 적합
        arr = new int[size];
        head = n;
        tail = -1;
        for(int i=0;i<n;i++) arr[i]=i+1; //i번째에 i+1번 사람 저장
    }

    public void enqueue(int x){
        if(head == arr.length) head = 0;
        arr[head++]=x;
    }

    public int dequeue(){
        if(tail == arr.length-1) tail = -1; //해당 인덱스 자체에는 값이 없음?
        return arr[++tail];
    }
}

//%연산자 이용 - 큐 용량 늘리기
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        var n = sc.nextInt(); //총 인원수
        var k = sc.nextInt(); //제거 위치
        Queue q = new Queue(n);
        int [] result = new int[n]; //인원수만큼
        int cnt = 0; //인원수 만큼 차면 종료하기 위해 선언

        for(int i=0; cnt!=n; i++){
            if((i+1)%k==0) result[cnt++] = q.dequeue(); //디큐해서 result에 저장
            else {
                int temp = q.dequeue();
                q.enqueue(temp); // 디큐해서 맨뒤에 엔큐
            }
        }
        System.out.print("<");
        for(int i=0; i<n-1; i++) System.out.print(result[i]+", ");
        System.out.print(result[n-1]+">");
    }
}