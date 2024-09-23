import ThreadRunnable.*
import sun.awt.Mutex

fun main(args: Array<String>) {
    val mutex = Any()

    val thrd_A = Thread(ThreadRunnable('A', mutex))
    val thrd_B = Thread(ThreadRunnable('B', mutex))
    val thrd_C = Thread(ThreadRunnable('C', mutex))
    val thrd_D = Thread(ThreadRunnable('D', mutex))

    thrd_A.start()
    thrd_B.start()
    thrd_C.start()
    thrd_D.start()

    thrd_A.join()
    thrd_B.join()
    thrd_C.join()
    thrd_D.join()
}