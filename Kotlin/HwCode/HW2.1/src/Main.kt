/* HW2.1
* made by jung choi(22112155)
* upload : https://github.com/chlwjd0803/YU_Kotlin_repo
*/

import java.util.Scanner
import kotlin.math.pow
import kotlin.math.sqrt

fun printArr(arr : IntArray) {
    for(i in 0 .. 9) print("%4d".format(arr[i]))
    println()
}

fun rev_printArr(arr : IntArray) {
    for(i in 9 downTo 0) print("%4d".format(arr[i]))
    println()
}

fun insertionSort(arr : IntArray) {
    val size = arr.size
    for(i in 1 until size){
        var key = arr[i]
        var j = i-1
        while(j>=0){
            if(arr[j] >= key) arr[j+1] = arr[j]
            else break
            j--
        }
        arr[j+1] = key //j가 한번 감소되었기 때문에
    }
}

fun getAvg(arr : IntArray) : Double{
    var sum = 0.0
    for(i in 0..9) sum += arr[i]
    return sum/arr.size
}

fun getVari(arr : IntArray, avg : Double) : Double{
    var sum = 0.0
    for(i in 0..9) sum += (arr[i]-avg).pow(2)
    return sum/10
}

fun main(args: Array<String>) {
    val intArray = IntArray(10)
    val cin = Scanner(System.`in`)
    var data : Int
    print("Enter 10 integers : ")
    for(i in 0..9) {
        data = cin.nextInt()
        intArray[i] = data
    }
    print("Input data before sorting : ")
    printArr(intArray)

    insertionSort(intArray)
    print("Input data after sorting : ")
    printArr(intArray)

    print("In reverse order : ")
    rev_printArr(intArray)

    val max = intArray[9] //정수
    val min = intArray[0] //정수
    val avg = getAvg(intArray) //실수
    val vari = getVari(intArray, avg) //실수
    val std = sqrt(vari) //실수

    print("Statistics :Statistics of the array: min(%d), max(%d), avg(%f), var(%f), std(%f)".format(min, max, avg, vari, std))
}