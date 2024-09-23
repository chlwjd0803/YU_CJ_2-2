package Mtrx
import Mtrx.Mtrx

class Mtrx {
    var mtrx_name: String? = null
    lateinit var mtrx_data: Array<DoubleArray>
    var n_row = 0
    var n_col = 0

    constructor(nm: String?, n_row: Int, n_col: Int){
        mtrx_name = nm
        mtrx_data = Array(n_row) { DoubleArray(n_col) }
        this.n_row = n_row
        this.n_col = n_col
    }

    constructor(nm: String?, n_row : Int, n_col : Int, dM_data: DoubleArray) {
        mtrx_name = nm
        mtrx_data = Array(n_row) { DoubleArray(n_col) }
        this.n_row = n_row
        this.n_col = n_col
        var count = 0
        for(r in 0 until n_row) for(c in 0 until n_col) mtrx_data[r][c] = dM_data[count++]
    }

    override fun toString() : String {
        var str: String = "%s = \n".format(mtrx_name)
        for (r in 0 until n_row) {
            for (c in 0 until n_col) str += "%7.2f".format(mtrx_data[r][c])
            str += "\n"
        }
        return str
    }

    fun setName(nm: String?) { mtrx_name = nm }

    operator fun plus(other: Mtrx) : Mtrx{
        val mR = Mtrx("mR", n_row, n_col)
        for(r in 0 until n_row) for(c in 0 until n_col)
            mR.mtrx_data[r][c] = mtrx_data[r][c] + other.mtrx_data[r][c]
        return mR
    }

    operator fun minus(other: Mtrx) : Mtrx{
        val mR = Mtrx("mR", n_row, n_col)
        for(r in 0 until n_row) for(c in 0 until n_col)
            mR.mtrx_data[r][c] = mtrx_data[r][c] - other.mtrx_data[r][c]
        return mR
    }

    operator fun times(other: Mtrx) : Mtrx{
        val mR = Mtrx("mR", n_row, other.n_col)
        var temp_sum: Double
        for(r in 0 until n_row) for(c in 0 until other.n_col){
            temp_sum = 0.0
            for(k in 0 until n_col) temp_sum += mtrx_data[r][k] * other.mtrx_data[k][c]
            mR.mtrx_data[r][c] = temp_sum
        }
        return mR
    }
}

fun main(args : Array<String>){
    val dA = doubleArrayOf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0)
    val dB = doubleArrayOf(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0)
    val dC = doubleArrayOf(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)

    val mA = Mtrx("mA", 3, 5, dA)
    val mB = Mtrx("mB", 3, 5, dB)
    val mC = Mtrx("mC", 5, 3, dC)
    println(mA)
    println(mB)
    println(mC)

    val mD: Mtrx = mA + mB
    mD.setName("mD = mA + mB")
    println(mD)

    val mE: Mtrx = mA - mB
    mE.setName("mE = mA - mB")
    println(mE)

    val mF: Mtrx = mA * mC
    mF.setName("mF = mA * mC")
    println(mF)
}