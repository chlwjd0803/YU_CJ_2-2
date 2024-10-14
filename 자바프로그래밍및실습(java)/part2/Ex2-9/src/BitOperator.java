
public class BitOperator {
    public static void main(String[] args) {
        short a = (short)0x55ff; short b = (short)0x00ff;

        // 비트 논리 연산
        System.out.println("[비트 연산 결과]");
        System.out.printf("%04x\n", (short)(a & b)); // 비트 AND
        System.out.printf("%04x\n", (short)(a | b)); // 비트 OR
        System.out.printf("%04x\n", (short)(a ^ b)); // 비트 XOR
        System.out.printf("%04x\n", (short)(~a)); // 비트 NOT
        byte c = 20; // 0x14
        byte d = -8; // 0xf8

        // 비트 시프트 연산
        System.out.println("[시프트 연산 결과]");
        System.out.println(c <<2); // c를 2비트 왼쪽 시프트
        System.out.println(c >>2); // c를 2비트 오른쪽 시프트. 0 삽입
        System.out.println(d >>2); // d를 2비트 오른쪽 시프트. 1 삽입
        System.out.printf("%x\n", (d >>>2)); // d를 2비트 오른쪽 시프트. 0 삽입
        //원래 비트 시프트는 연산을 취하기 전에 int형으로 변환하여 4바이트로 연산한다.
        //일반적으로 부호를 유지하는 산술적 시프트 << >> 는 출력되는 값에 문제가 없지만
        //논리적 시프트인 >>>는 최상위 비트를 0으로 채우기에 부호가 깨지며 다른값이 나오게 되는것이다.
    }
}