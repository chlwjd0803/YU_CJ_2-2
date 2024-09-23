import HM.*

fun main() {
    val hmap = HashMap<String, Int>()
    val L_number_names = arrayOf("zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten")
    for (i in 0..L_number_names.size -1) { hmap.put(L_number_names[i], i) }
    hmap.print()
    var hmap_keys = hmap.keys()
    var hmap_values = hmap.values()
    println("hmap keys = " + hmap_keys)
    println("hmap values = " + hmap_values)
}