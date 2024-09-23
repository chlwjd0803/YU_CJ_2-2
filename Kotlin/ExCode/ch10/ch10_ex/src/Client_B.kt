import java.io.*
import java.net.*
fun main() {
// Connect to the main server
    val serverClientB = Socket("localhost", 9999)
    println("Client_B is now connected to main server")
    val serverInput = BufferedReader(InputStreamReader(serverClientB.getInputStream()))
    val serverOutput = PrintWriter(serverClientB.getOutputStream(), true)
// Connect to Client_A
    val peer = Socket("localhost", 9998)
    println("Client_B connected to peer (${peer.inetAddress.hostAddress}:${peer.port})")
    val peer_Input = BufferedReader(InputStreamReader(peer.getInputStream()))
    val peer_Output = PrintWriter(peer.getOutputStream(), true)
    for (count in 0..100) {
        var msgToServer = "Client_B:: %03d".format(count)
        serverOutput.println(msgToServer)
        println("Client_B sent to server: $msgToServer")
        println("Client_B:: response from main server: ${serverInput.readLine()}")
        var msgToPeer = "Client_B (to peer) :: %03d".format(count)
        peer_Output.println(msgToPeer)
        println("Client_B sent to peer: $msgToPeer")
        println("Client_B received from peer: ${peer_Input.readLine()}")
        Thread.sleep(1500) //딜레이조절
    }
    serverClientB.close() // closing the socket to main server
    println("Client_B disconnected from main server")
    peer.close()
    println("Client_B disconnected from peer")
}