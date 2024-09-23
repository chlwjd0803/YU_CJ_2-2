import java.io.*
import java.net.*

fun main() {
    val server = ServerSocket(9999) // serve용 socket 생성
    println("Main Server (${server.inetAddress.hostAddress}) using port (${server.localPort}) just started, and waiting for clients' connection requests")
    while (true) {
        val client = server.accept() // client 접속 요청을 승인
        println("Client (${client.inetAddress.hostAddress}) is just connected .....")
        Thread {
            val input = BufferedReader(InputStreamReader(client.getInputStream()))
            val output = PrintWriter(client.getOutputStream(), true)
            var message: String? = ""
            while (client.isConnected && input.readLine().also { message = it } != null) {
            println("Received: $message from ${client.inetAddress.hostAddress}")
            output.println("Echo: $message") // echo back to client
        }
            client.close()
            println("Client (${client.inetAddress.hostAddress},${client.port}) is disconnected now")
        }.start()
    }
}