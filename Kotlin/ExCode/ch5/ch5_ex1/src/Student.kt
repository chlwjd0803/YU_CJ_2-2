package MyKotlinClasses

class Student : Person {
    var st_id : Int = 0
    val dmmy3 = println("(7) Declaration of Student.st_id")
    var st_major : String = ""
    val dmmy4 = println("(8) Declaration of Student.st_major")
    init {
        println("(9) Student.init{}")
    }
    constructor(nm: String, rgID: Int, stID: Int, mjr: String, arg: Unit=println("(1) Student secondary constructor default argument")): super(nm, rgID) {
        this.st_id = stID
        this.st_major = mjr
        println("(10) Initialization of st_id and major in Student secondary constructor")
    }
    override fun print() { //오버라이딩을 통한 기본클래스 함수 무력화
        println("Student(name=%s, reg_id=%d, st_id=%d, major=%s)".format(this.name,
            this.reg_id, this.st_id, this.st_major))
    }
    override fun toString() : String {
        var str = "Student(name=%s, reg_id=%d, st_id=%d, major=%s)".format(this.name,
            this.reg_id, this.st_id, this.st_major)
        return str
    }
}