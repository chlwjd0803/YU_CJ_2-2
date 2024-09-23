package ThreadRunnable

class ThreadRunnable(var mark: Char, var mutex : Any) : Runnable {
    override fun run() {
        for(i in 1..50) {
            synchronized(mutex){
                for (k in 0..50) {
                    print("%c".format(mark))
                    Thread.sleep(10)
                }
            }
            println()
            Thread.sleep(100)
        }
    } // end while
}