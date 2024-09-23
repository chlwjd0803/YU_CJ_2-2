import java.util.Scanner

fun main(args: Array<String>){
    val cin = Scanner(System.`in`)

    while(true) {
        print("Enter your student_id last 4 number (enter -1 exit) : ")
        val studentId = cin.nextInt()
        if(studentId == -1) break
        print("Enter lec_class number (enter -1 exit) : ")
        val classNum = cin.nextInt()
        if(classNum == -1) break

        val stuCls = ((studentId % classNum) + 65).toChar()
        println("Your class is $stuCls")
    }
}