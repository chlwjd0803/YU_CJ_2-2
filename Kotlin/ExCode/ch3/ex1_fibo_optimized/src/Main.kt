import kotlin.system.measureTimeMillis
import java.util.Scanner

val FIBO_MAX = 100

fun Fibo_SR(n : Int) : Double{
    if(n<0) println("Error in Fibonacci series, given n ($n) is negative!!")
    if((n>=0) && (n<=1)) return n.toDouble()
    else {
        var fiboN = Fibo_SR(n-2) + Fibo_SR(n-1)
        return fiboN
    }
}

var fiboTbl : DoubleArray = DoubleArray(FIBO_MAX+1){-1.0}
fun Fibo_Dyn(n:Int) : Double{
    if(n>FIBO_MAX){
        println("Exception in Fibo_Dyn given n ($n) is beyond the FIBO_MAX($FIBO_MAX)!")
        return -1.0
    }
    var fiboN : Double
    if((n>=0) && (n<=1)) return n.toDouble()
    else if(fiboTbl[n] != -1.0) return fiboTbl[n]
    else{
        fiboN = Fibo_Dyn(n-1) + Fibo_Dyn(n-2)
        fiboTbl[n] = fiboN
        return fiboN
    }
}

fun main(args: Array<String>){
    val cin = Scanner(System.`in`)
    print("Input range (start, end (upto 100) step) of Fibonacci series : ")
    val start = cin.nextInt()
    val end = cin.nextInt()
    val FiboStep = cin.nextInt()

    print("By Simple Recursive (SR) or Dynamic Programming (Dyn) : ")
    var mode = cin.next()
    var fiboN : Double
    var tmsFibo : Long

    if(mode == "SR"){
        println("Fibonacci Series (by Simple Recursive)")
        for(n in start..end step FiboStep) {
            tmsFibo = measureTimeMillis { fiboN = Fibo_SR(n) }
            println("%3d-th Fibo_n = %25.0f (took %8d msec)".format(n, fiboN, tmsFibo))
        }
    }

    else{
        println("Fibonacci Series (by Dynamic Programming)")
        for(n in start..end step FiboStep){
            tmsFibo = measureTimeMillis { fiboN = Fibo_Dyn(n) }
            println("%3d-th Fibo_n = %25.0f (took %8d msec)".format(n, fiboN, tmsFibo))
        }
    }
    cin.close()
}