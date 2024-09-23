/*
* this code is YU Ex code.
*
* 오버라이딩 개념 중요
 */
import MyKotlinClasses.Student
import MyKotlinClasses.Employee
// 기본클래스는 별도로 필요하지 않음

fun main(args: Array<String>) {
    val st_nm = "Kim"
    val regID = 10000
    val stID = 20000
    val mjr = "ICT"
    var c1 = Student(st_nm, regID, stID, mjr) //Student 객체 생성
    println("c1 = " + c1)
    println()
    var e1 = Employee("Choi", 12000, 7654, "Samsung", "MobileNetwork") //Employee 객체 생성
    println("e1 = " + e1)
}