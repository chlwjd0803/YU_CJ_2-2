fun main(args: Array<String>) {
    val kor_str = "대한민국 한글"
    val kor_bytes = kor_str.toByteArray()
    val str_byte = String(kor_bytes)
    println(str_byte)
    println(kor_str) //둘다 되네?
}