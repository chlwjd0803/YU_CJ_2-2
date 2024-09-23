import Graph.*
import java.io.File
import java.util.*

fun printPath(path: List<Vertex>?) {
    if (path != null) {
        for (i in path.indices) {
            val v: Vertex = path[i]
            print("%s".format(v.getName()))
            if (i != path.size - 1) print("->")
        }
    }
    println()
}

fun main(args: Array<String>) {
    val fname = "graph_weighted_edges.txt" //경로를 해당 저장소 맨 상위폴더에 저장해야함 ch9_ex2 폴더안
    val fin = Scanner(File(fname))
    var src: String?
    var dest: String?
    var weight: Int
    val dag = DirectedAcyclicGraph("DirectedAcyclicGraph")
    var vrtx: Vertex
    var vrtx_src: Vertex?
    var vrtx_dest: Vertex?
    while (fin.hasNext()) {
        src = fin.next()
        dest = fin.next()
        weight = fin.nextInt()
        if (dag.findVertex(src) == null) {
            dag.addVertex(src) }
        vrtx_src = dag.findVertex(src)
        if (dag.findVertex(dest) == null) {
            dag.addVertex(dest) }
        vrtx_dest = dag.findVertex(dest)
        dag.addDirectedWeightedEdge(vrtx_src!!, vrtx_dest!!, weight)
        // add directional weightedEdges
    } // end while
    fin.close()
    //prints the corresponding adjacency list for the graph
    dag.printWeightedGraph()
    dag.initDistTable()
    dag.printDistTable()
    val path: List<Vertex>?
    val vStart = dag.vrtxArray[0]
    val vEnd = dag.vrtxArray[3]
    println("DAG ShortestPathFirst (%s -> %s) . . . . ".format(vStart.getName(), vEnd.getName()))
    path = dag.DAGShortestPath(vStart, vEnd)
    println("Result DAG ShortestPathFirst (%s -> %s) : ".format(vStart.getName(), vEnd.getName()))
    printPath(path)
}