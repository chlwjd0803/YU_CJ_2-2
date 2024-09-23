/* HW3.2
* made by jung choi(22112155)
* upload : https://github.com/chlwjd0803/YU_Kotlin_repo
*/

import java.util.*
import kotlin.system.measureNanoTime
import kotlin.system.measureTimeMillis

fun shuffleBigIntArray(array: IntArray) { val size = array.size
    var j: Int
    var temp: Int
    /* shuffle */
    for (i in 0 until size) {
        j = (Math.random() * size).toInt()
        if (j == i) continue
        temp = array[i]
        array[i] = array[j]
        array[j] = temp
    }
}

fun genBigRandIntArray(size: Int, offset: Int): IntArray { val bigIntArray = IntArray(size)
    var j: Int
    var temp: Int
    for (i in 0 until size) bigIntArray[i] = i + offset
    /* shuffle */
    shuffleBigIntArray(bigIntArray)
    return bigIntArray
}

fun selection_sort(array: IntArray) {
    /* sort given array with selection_sort algorithm */
    var temp: Int
    var min_idx: Int
    val size = array.size
    for (i in 0 until size - 1) {
        min_idx = i
        for (j in i + 1 until size) {
            if (array[min_idx] > array[j]) {
                min_idx = j
            }
        }
        if (min_idx != i) {
            temp = array[i]
            array[i] = array[min_idx]
            array[min_idx] = temp
        }
    }
} // end selection_sort()

fun insertion_sort(array: IntArray) {
    /* sort given array with insertion_sort algorithm */
    var temp: Int
    var i: Int
    var k: Int
    val size = array.size
    k = 1
    while (k <= size - 1) {
        temp = array[k]
        i = k
        while (i > 0 && array[i - 1] >= temp) {
            array[i] = array[i - 1] // shift right to make a room
            --i
        }
        array[i] = temp
        k++
    }
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

fun _quickSort(array: IntArray, left: Int, right: Int)
{
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

fun quick_sort(array: IntArray) {
    var size = array.size; _quickSort(array, 0, size-1);
}

fun PM_SortingAlgorithms_IntArray() {
    var big_size: Int
    val test_sizes = intArrayOf(10, 20, 30, 40, 50, 70, 100, 200, 500, 1000)
    val offset = 0
    var bigRandIntArray: IntArray
    var tns_insert : Long
    var tns_select : Long
    var tns_quick : Long
    println("Comparisons of Sorting Algorithms (measured time in milli-seconds)")
    println("%10s %15s %15s %15s".format("test_size", "quick_sort", "insert_sort", "select_sort"))
    for (test_size in test_sizes) {
        bigRandIntArray = genBigRandIntArray(test_size, offset);
        tns_quick = measureNanoTime {
            quick_sort(bigRandIntArray)
        }
        tns_insert = measureNanoTime {
            insertion_sort(bigRandIntArray)
        }
        shuffleBigIntArray(bigRandIntArray)
        tns_select = measureNanoTime {
            selection_sort(bigRandIntArray)
        }

        println("%10d %15d %15d %15d".format(test_size, tns_quick, tns_insert, tns_select))
    }
}

fun main(args: Array<String>) {
    PM_SortingAlgorithms_IntArray()
}