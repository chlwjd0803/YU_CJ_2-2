/* HW1.2 Fibonacci speed optimized ver
* made by jung choi(22112155)
* upload : https://github.com/chlwjd0803/YU_Kotlin_repo
*/

import java.util.*
fun Fibo(n : Int) : LongArray{
    var farr = LongArray(n+1) //코틀린 자동 동적할당, 피보나치 수열 결과값을 저장하는 곳
    farr[0] = 0
    farr[1] = 1
    for (i in 2..n) farr[i] = farr[i - 1] + farr[i - 2]
    return farr
}

fun main(args: Array<String>) {
    val cin = Scanner(System.`in`)
    print("Input n to generate Fibonacci series (0 ~ n) : ")
    val n = cin.nextInt()
    val farr = Fibo(n)
    for(i in 0..n) print("Fibo(%3d) = %20d\n".format(i, farr[i]))
    cin.close()
}