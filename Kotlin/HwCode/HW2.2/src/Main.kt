/* HW2.2 Mtrx
* made by jung choi(22112155)
* upload : https://github.com/chlwjd0803/YU_Kotlin_repo
*/

fun printMtrx(mtrx_name: String, mtrx_data: Array<DoubleArray>) {
    println("$mtrx_name =")
    for(i in mtrx_data.indices) {
        for(j in mtrx_data[i].indices) print("%.2f\t".format(mtrx_data[i][j]))
        println()
    }
}

fun addMtrx(mA_data: Array<DoubleArray>, mB_data: Array<DoubleArray>): Array<DoubleArray> {
    var mSum = mA_data //배열의 크기를 복사할 수 있어서 그대로 복사
    for(i in mA_data.indices) for(j in mA_data[i].indices) mSum[i][j] = mA_data[i][j] + mB_data[i][j]
    //mSum의 값을 모두 변경하고 반환
    return mSum
}

fun subMtrx(mA_data: Array<DoubleArray>, mB_data: Array<DoubleArray>): Array<DoubleArray> {
    var mSub = mA_data //배열의 크기를 복사할 수 있어서 그대로 복사
    for(i in mA_data.indices) for(j in mA_data[i].indices) mSub[i][j] = mA_data[i][j] - mB_data[i][j]
    //mSum의 값을 모두 변경하고 반환
    return mSub
}

fun mulMtrx(mA_data: Array<DoubleArray>, mB_data: Array<DoubleArray>): Array<DoubleArray> {
    val row = mA_data.size
    val col = mB_data[0].size
    val result = Array(row) { DoubleArray(col) }

    for (i in 0 until row) {
        for (j in 0 until col) {
            var sum = 0.0
            for (k in 0 until col) {
                sum += mA_data[i][k] * mB_data[k][j]
            }
            result[i][j] = sum
        }
    }
    return result
}

fun main() {
    val mA = arrayOf(
        doubleArrayOf(1.0, 2.0, 3.0, 4.0, 5.0),
        doubleArrayOf(6.0, 7.0, 8.0, 9.0, 10.0),
        doubleArrayOf(11.0, 12.0, 13.0, 14.0, 15.0))
    val mB = arrayOf(
        doubleArrayOf(1.0, 0.0, 0.0, 0.0, 0.0),
        doubleArrayOf(0.0, 1.0, 0.0, 0.0, 0.0),
        doubleArrayOf(0.0, 0.0, 1.0, 0.0, 0.0))
    val mAddAB: Array<DoubleArray>
    val mSubAB: Array<DoubleArray>
    print("mA (nRow = %d, nCol = %d)\n".format(mA.size, mA[0].size))
    printMtrx("mA", mA)
    printMtrx("mB", mB)
    mAddAB = addMtrx(mA, mB)
    printMtrx("mAddAB", mAddAB)
    mSubAB = subMtrx(mA, mB)
    printMtrx("mSubAB", mSubAB)
    val mC = arrayOf(
        doubleArrayOf(1.0, 0.0, 0.0),
        doubleArrayOf(0.0, 1.0, 0.0),
        doubleArrayOf(0.0, 0.0, 1.0),
        doubleArrayOf(0.0, 0.0, 0.0),
        doubleArrayOf(0.0, 0.0, 0.0) )
    val mMulAC: Array<DoubleArray>
    printMtrx("mA", mA)
    printMtrx("mC", mC)
    mMulAC = mulMtrx(mA, mC)
    printMtrx("mMulAC", mMulAC)
}