package MyKotlinClasses

class Employee : Person {
    private var emp_id : Int = 0
    private var company: String? = null
    private var department: String? = null
    val dmmy3 = println("(7-8) Declaration of Employee.emp_id, company, department")
    init{
        println("(9) Employee.init{}")
    }
    constructor (name: String, reg_ID: Int, emp_id: Int, company: String, department: String, arg: Unit=println("(1) Employee secondary constructor default argument")) : super(name, reg_ID) {
        this.emp_id = emp_id
        this.company = company
        this.department = department
    }
    override fun toString(): String {
        var str = String.format("Employee(")
        str += super.toString()
        str += String.format("), company:%s, dept:%s, emp_ID:%d)\n", company, department, emp_id)
        return str
    }
}