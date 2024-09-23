import java.util.Scanner
import java.io.*
import Mtrx.Mtrx

@Throws(IOException::class)
fun main(args: Array<String>) {
    val fin_name : String = "mtrx_data.txt"
    val fout_name : String = "mtrx_operation_result.txt"
    val fin = Scanner(File(fin_name))
    val fout : FileWriter = FileWriter(File(fout_name))
    val mtrxs = Array<Mtrx> (6) {Mtrx("")}
    mtrxs[0].fget_Mtrx(fin)
    mtrxs[1].fget_Mtrx(fin)
    mtrxs[2].fget_Mtrx(fin)
    mtrxs[0].printMtrx(); mtrxs[0].fprintMtrx(fout)
    mtrxs[1].printMtrx(); mtrxs[1].fprintMtrx(fout)
    mtrxs[2].printMtrx() ;mtrxs[2].fprintMtrx(fout)
    mtrxs[3] = mtrxs[0].addMtrx(mtrxs[1]); mtrxs[3].setMtrxName("mAdd_AB"); mtrxs[3].printMtrx(); mtrxs[3].fprintMtrx(fout)
    mtrxs[4] = mtrxs[0].subMtrx(mtrxs[1]); mtrxs[4].setMtrxName("mSub_AB"); mtrxs[4].printMtrx(); mtrxs[4].fprintMtrx(fout)
    mtrxs[5] = mtrxs[0].mulMtrx(mtrxs[2]); mtrxs[5].setMtrxName("mMul_AC"); mtrxs[5].printMtrx(); mtrxs[5].fprintMtrx(fout)
    fout.close();
}