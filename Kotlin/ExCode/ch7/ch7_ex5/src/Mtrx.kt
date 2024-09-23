package Mtrx

import java.io.FileWriter
import java.io.IOException
import java.util.*
class Mtrx {
    var m_name: String? = null
    var n_row = 0
    var n_col = 0
    var mtrx_data = Array(n_row) { DoubleArray(n_col) }
    constructor(nm: String) {
        this.m_name = nm
        this.n_row = 0
        this.n_col = 0
    }
    constructor(nm: String, n_row: Int, n_col: Int) {
        this.m_name = nm
        this.n_row = n_row
        this.n_col = n_col
        this.mtrx_data = Array(n_row) { DoubleArray(n_col) }
    }
    constructor(nm: String, n_row: Int, n_col: Int, m_data: Array<DoubleArray>) {
        this.m_name = nm
        this.n_row = n_row
        this.n_col = n_col
        this.mtrx_data = Array(n_row) { DoubleArray(n_col) }
        for (r in 0 until n_row) {
            for (c in 0 until n_col) {
                mtrx_data[r][c] = m_data[r][c]
            }
        }
    }

    fun fget_Mtrx(fin: Scanner): Mtrx {
        this.m_name = fin.next()
        this.n_row = fin.nextInt()
        this.n_col = fin.nextInt()
        this.mtrx_data = Array(n_row) { DoubleArray(n_col) }
        //mtrx.mtrx_data = Array<DoubleArray>(mtrx.n_row)
        // { DoubleArray(mtrx.n_col) }
        for (r in 0 until n_row) {
            for (c in 0 until n_col) {
                this.mtrx_data[r][c] = fin.nextDouble()
            }
        }
        return this
    }
    fun setMtrxName(nm: String) {
        m_name = nm
    }

    fun printMtrx() {
        System.out.printf("%s (%d x %d) = \n", m_name, n_row, n_col)
        for (r in 0 until n_row) {
            for (c in 0 until n_col) {
                System.out.printf("%7.2f", mtrx_data[r][c])
            }
            System.out.printf("\n")
        }
    }
    @Throws(IOException::class)
    fun fprintMtrx(fout : FileWriter) {
        var str_data: String?
        fout.write(m_name)
        fout.write(" ")
        fout.write(String.format("%3d", n_row))
        fout.write(" ")
        fout.write(String.format("%3d", n_col))
        fout.write("\n")
        for (r in 0 until n_row) {
            for (c in 0 until n_col) {
                str_data = java.lang.String.format("%7.2f", this.mtrx_data[r][c])
                fout.write(str_data)
            }
            fout.write("\n")
        }
        fout.flush()
    }

    fun addMtrx(other: Mtrx): Mtrx {
        val m_result = Mtrx("R", n_row, n_col)
        for (r in 0 until n_row) {
            for (c in 0 until n_col) {
                m_result.mtrx_data[r][c] =
                    this.mtrx_data[r][c] + other.mtrx_data[r][c]
            }
        }
        return m_result
    }
    fun subMtrx(other: Mtrx): Mtrx {
        val m_result = Mtrx("R", n_row, n_col)
        for (r in 0 until n_row) {
            for (c in 0 until n_col) {
                m_result.mtrx_data[r][c] =
                    mtrx_data[r][c] - other.mtrx_data[r][c]
            }
        }
        return m_result
    }

    fun mulMtrx(other: Mtrx): Mtrx {
        val m_result = Mtrx("R", n_row, other.n_col)
        var temp_sum = 0.0
        for (r in 0 until n_row) {
            for (c in 0 until other.n_col) {
                temp_sum = 0.0
                for (k in 0 until n_col) {
                    temp_sum += mtrx_data[r][k] * other.mtrx_data[k][c]
                }
                m_result.mtrx_data[r][c] = temp_sum
            }
        }
        return m_result
    }
}