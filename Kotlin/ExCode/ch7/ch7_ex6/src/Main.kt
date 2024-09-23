import java.io.InputStreamReader
import java.io.FileWriter
import java.io.IOException
import java.io.FileInputStream

//한글 입력 시 실행창에는 깨져보이나 텍스트파일에는 정상 입력 되어있음
fun main() {
    //
    var cin : InputStreamReader = InputStreamReader(System.`in`);
    val fout : FileWriter
    var ch : Int;
    var fout_name : String = "keyboard_input_text.txt";
    System.out.printf("Input text sentences (Ctrl-D to end) : "); //쓰기모드, 출력형
    try {
        fout = FileWriter(fout_name);
        while(true) {
            ch = cin.read()
            if (ch == -1)
                break
            fout.write(ch);
        }
        cin.close();
        fout.close();
    }
    catch (e: IOException) { //입출력 예외 처리
        System.out.printf("Exception in input/out !!\n");
    }

    //쓴 파일에 있는 내용 다시 읽어 프로그램에서 출력
    val fin_name : String = "keyboard_input_text.txt";
    val fin : FileInputStream
    System.out.printf("\nContents of textfile (%s) :\n", fin_name);
    try {
        fin = FileInputStream(fin_name);
        cin = InputStreamReader(fin, "MS949"); // char set for korean text file reading
        System.out.printf("Encoding char set = %s\n", cin.getEncoding());
        while (true) {
            ch = cin.read()
            if (ch == -1)
                break
            System.out.printf("%c", ch);
        }
        cin.close();
        fin.close();
    }
    catch (e : IOException) {
        System.out.printf("IOException in text reading !!\n");
    }
}