/* HW3.1
* made by jung choi(22112155)
* upload : https://github.com/chlwjd0803/YU_Kotlin_repo
*/

import java.util.Scanner

fun genBigRandIntArray(size: Int, offset: Int): IntArray {
    val bigIntArray = IntArray(size)
    var j: Int
    var temp: Int
    for (i in 0 until size) bigIntArray[i] = i + offset
    for (i in 0 until size) {
        j = (Math.random() * size).toInt()
        if (j == i)
            continue
        temp = bigIntArray[i]
        bigIntArray[i] = bigIntArray[j]
        bigIntArray[j] = temp
    }
    return bigIntArray
}

fun printBigArraySample(bigArray: IntArray, per_line: Int, sample_lines: Int) {
    var samcnt = 0
    for(i in 0 until per_line*sample_lines) {
        if(samcnt == per_line) {
            samcnt=0
            println()
        }
        print("%8d".format(bigArray[i]))
        samcnt++
    }
    println("\n. . . . .")
    val size = bigArray.size
    for(i in (size-(sample_lines*per_line)) until size){
        if(samcnt == per_line){
            println()
            samcnt=0
        }
        print("%8d".format(bigArray[i]))
        samcnt++
    }
    println()
}

fun _partition(array: IntArray, left: Int, right: Int, pivotIndex: Int): Int {
    val pivotValue: Int // pivot value
    var newPI: Int // new pivot index
    var temp: Int
    var i: Int
    pivotValue = array[pivotIndex]
    temp = array[pivotIndex]
    array[pivotIndex] = array[right]
    array[right] = temp // Move pivot to end
    newPI = left
    i = left
    while (i <= right - 1) {
        if (array[i] <= pivotValue) {
            temp = array[i]
            array[i] = array[newPI]
            array[newPI] = temp
            newPI = newPI + 1
        }
        i++
    }
    // swap array[storeIndex] and array[right]; Move pivot to its final place
    temp = array[newPI]
    array[newPI] = array[right]
    array[right] = temp
    return newPI
}

fun _quickSort(array: IntArray, left: Int, right: Int) {
    var pI : Int
    var newPI : Int // pivot index
    if (left >= right) {
        return;
    }
    pI = (left + right) / 2;
    newPI = _partition(array, left, right, pI);
    if (left < (newPI - 1)) { _quickSort(array, left, newPI - 1);
    // recursively sort elements on the left of pivotNewIndex
    }
    if ((newPI + 1) < right) { _quickSort(array, newPI + 1, right);
    // recursively sort elements on the right of pivotNewIndex
    }
}

fun quickSort(array: IntArray) {
    var size = array.size; _quickSort(array, 0, size-1)
}


fun main(args: Array<String>) {
    val cin = Scanner(System.`in`)
    var big_size: Int
    val offset = 0
    var bigRandIntArray: IntArray
    while (true) {
        print("input big_size (> 32767) to generate non-duplicated random big integer array (0 to terminate) : ")
        big_size = cin.nextInt()
        if (big_size == 0)
            break
        bigRandIntArray = genBigRandIntArray(big_size, offset)
        System.out.printf("Before sorting, size = %d, offset = %d\n", big_size, offset)
        printBigArraySample(bigRandIntArray, 10, 2)
        quickSort(bigRandIntArray)
        System.out.printf("After sorting, size = %d, offset = %d\n", big_size, offset)
        printBigArraySample(bigRandIntArray, 10, 2)
    }
}