/* HW1.1 Sorting integer
* made by jung choi(22112155)
* upload : https://github.com/chlwjd0803/YU_Kotlin_repo
*/
import java.util.Scanner

fun printArray(arr : IntArray) {
    val size = arr.size
    for (i in 0 until size) {
        print("%3d".format(arr[i])) }
    println()
}

//아래 삽입정렬을 재이해하여 다시 작성하였습니다.
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

fun main(args: Array<String>) {
    val intArray = IntArray(10)
    val cin = Scanner(System.`in`)
    var data : Int
    print("Enter 10 integers : ")
    for(i in 0..9) {
        data = cin.nextInt()
        intArray[i] = data }
    print("Input data before sorting : ")
    printArray(intArray)
    insertionSort(intArray)
    print("Input data after sorting : ")
    printArray(intArray)
}