fun main(args: Array<String>){
    val hm_inum_cnum = HashMap<Int, String>()
    val charnum = arrayOf("Zero", "One", "Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine")

    for(i in 0..9) hm_inum_cnum[i] = charnum[i]

    val keys: Set<Int> = hm_inum_cnum.keys
    val it = keys.iterator()
    while(it.hasNext()) {
        val key = it.next()
        val value = hm_inum_cnum[key]
        println("$key = $value")
    }
}