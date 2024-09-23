import java.io.FileReader
import java.io.IOException
@Throws(IOException::class)

fun main() {
    val file_name = "student_records.txt"
    var fin: FileReader? = null
    fin = FileReader(file_name)
    var ch: Int
    while (fin.read().also { ch = it } != -1) { //-1은 파일을 다 읽었다는 의미
        print(ch.toChar())
    }
    fin.close()
}