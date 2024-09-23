package MyKotlinClasses


//해당 클래스에서 상속을 시키려면 open을 사용해야함*********************
open class Person (){
    var name : String = ""
    val dmmy1 = println("(3) Declaration of Person.name")
    var reg_id : Int = 0
    val dmmy2 = println("(4) Declaration of Person.reg_id")
    init {
        println("(5) Person.init{}")
    }
    constructor(nm: String, regID: Int, arg: Unit=println("(2) Person secondary constructor default argument")) : this() {
        println("(6) Person primary constructor, initializing Person.name, Person.reg_id")
        this.name = nm
        this.reg_id = regID
    }
    open fun print() { //기본클래스의 오버라이딩 대상 함수는 처음에 open으로 정의
        println("Person(name=%s, reg_id=%d)".format(this.name, this.reg_id))
    }
    override fun toString() : String { //Any클래스에서 기본적으로 제공하기에 이 함수는 override로 정의해야한다.
        var str = "Person(name=%s, reg_id=%d)".format(this.name, this.reg_id)
        return str
    }
}