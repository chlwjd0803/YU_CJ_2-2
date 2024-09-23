package Graph
import java.util.*

class DirectedAcyclicGraph {
    var name: String? = null
    var num_vrtx = 0
    var vrtxArray = Vector<Vertex>()
    //List<Vertex> nodeList = new ArrayList<>();
    var wedges: MutableList<WeightedEdge> = ArrayList()
    lateinit var distTbl: Array<IntArray>
    var adjList = ArrayList<MutableList<Vertex>>()
    var dest_arrived = false // used in graph search algorithms
    //creating a constructor of the class Graph that creates graph
    constructor(nm: String?) {
        name = nm
    }
    fun addVertex(vrtxName: String): Vertex? {
        return if (findVertex(vrtxName) == null) {
            val newVrtx = Vertex(vrtxName)
            vrtxArray.add(newVrtx)
            newVrtx.setVID(num_vrtx)
            adjList.add(newVrtx.getVID(), ArrayList())
            num_vrtx++
            newVrtx
        }
        else {
            null
        }
    }
    fun findVertex(vrtxName: String): Vertex? {
        var vname: String
        for (v in vrtxArray) {
            vname = v.getName().toString()
            if (vname == vrtxName) return v }
        return null
    }
    fun addWeightedEdge(vrtx_src: Vertex, vrtx_dest: Vertex, weight: Int) {
        addDirectedWeightedEdge(vrtx_src, vrtx_dest, weight)
        addDirectedWeightedEdge(vrtx_dest, vrtx_src, weight)
    }
    fun addDirectedWeightedEdge(vrtx_src: Vertex, vrtx_dest: Vertex, weight: Int) {
        val wedge = WeightedEdge(vrtx_src, vrtx_dest, weight)
        wedges.add(wedge)
        vrtx_src.addWeightedEdge(vrtx_dest, weight)
        adjList[vrtx_src.getVID()].add(vrtx_dest)
    }
    fun initDistTable() {
        distTbl = Array(num_vrtx) { IntArray(num_vrtx) }
    // initialize distance table
        for (i in 0 until num_vrtx) {
            for (j in 0 until num_vrtx) {
                if (i == j)
                    distTbl[i][j] = 0
                else
                    distTbl[i][j] = Int.MAX_VALUE / 2 // to prevent integer overflow
                }
        }
    //set the edges to the undirected graph
        for (e in wedges) {
        //creating a new node (from source to destination) in the adjacency list
            val srcVID = e.getSrcVID()
            val destVID = e.getDestVID()
            distTbl[srcVID][destVID] = e.getWeight() }
    }
    fun printWeightedGraph() {
        System.out.printf("Vertices (num_vrtx = %d) : ", num_vrtx)
        for (i in 0 until num_vrtx) {
            print(vrtxArray[i].getName())
            print(" ")
        }
        println()
        System.out.printf("Adjacency List for the Graph is: \n")
        for (i in 0 until num_vrtx) {
            //for-each loop prints the neighboring vertices with current vertex
            val src = vrtxArray[i]
            print(src)
            print(" -> [ ")
            for (dest in adjList[i]) {
                print(dest)
                print(", ")
            }
            println("]")
    //increments the source by 1
        } // end while
    } // end printGraph()
    fun printDistTable() {
        var edge_weight: Int
        println("Distance Table :")
        print("     ")
        for (i in 0 until num_vrtx) {
            System.out.printf("%4s", vrtxArray[i].getName()) }
        print("\n-----+")
        for (i in 0 until num_vrtx) print("-----")
        println()
        for (i in 0 until num_vrtx) {
            System.out.printf("%4s |", vrtxArray[i].getName())
            for (j in 0 until num_vrtx) {
                edge_weight = distTbl[i][j]
                if (edge_weight >= Int.MAX_VALUE / 2)
                    print(" oo ") // simplified infinity symbol
                else
                    print("%3d ".format(edge_weight))
            }
            println()
        }
        println()
    }

    private fun _DFS(cur_start: Vertex, dest: Vertex, path: MutableList<Vertex>) {
        path.add(cur_start)
        if (cur_start.equals(dest)) { // arrived to destination
            dest_arrived = true
            return }
        val neighbors: List<Vertex> = adjList[cur_start.getVID()]
        for (v in neighbors) {
            if (path.contains(v)) continue // avoid cycle
            if (v.equals(dest)) { // arrived to destination
                path.add(v)
                dest_arrived = true
                break }
            if (!dest_arrived) {
                _DFS(v, dest, path)
                if (!dest_arrived) {
                    path.removeAt(path.size - 1) // pop the last added vertex
                    }
            }
                    if (dest_arrived) break
        }
    }
    fun DepthFirstSearch(start: Vertex, dest: Vertex): List<Vertex> {
        val path: MutableList<Vertex> = ArrayList()
        dest_arrived = false
        _DFS(start, dest, path)
        return path
    }

    fun BreadthFirstSearch(start: Vertex, dest: Vertex?): List<Vertex?> {
        for (v in vrtxArray) {
            v.visited = false
            v.prev = null
            v.level = - 1
        }
        start.level = 0
        start.visited = true
        start.prev = start
        var num_visited = 1 // just including start
        var searchLevel = 0
        while (num_visited < num_vrtx) {
            //print("BFS::searchLevel(%2d) :".format(searchLevel))
            for (v in vrtxArray) {
                if (v.visited === true && v.level === searchLevel) {
                    for (w in adjList[v.getVID()]) {
                        if (w.visited === false) {
                            w.visited = true // set as Visited w.level = searchLevel + 1 w.prev = v
                            num_visited++
//print(“%c ”.format(w))
                        }
                    }
                }
            }
            searchLevel++
//println();
        }
        val path = ArrayList<Vertex?>()
        var v = dest
        while (!v!!.equals(start)) {
            path.add(0, v)
        } // put v at front v = v.prev }path.add(0, v) // put v(start) at front
        return path
    }

    fun DijkstraShortestPath(start: Vertex, dest: Vertex): List<Vertex?> {
        val path = ArrayList<Vertex?>()
        if (dest.equals(start)) {
            path.add(dest)
            return path }
        val selectedVrtxs = ArrayList<Vertex?>()
        val remainVrtxs = ArrayList<Vertex?>()
        val vid_start = start.getVID()
        val vid_dest = dest.getVID()
        var minAccDist: Int
        var vAccDist: Int
        var minVID: Int
        var minVrtx: Vertex? = null
        for (v in vrtxArray) {
            if (v.equals(start)) {
                selectedVrtxs.add(v)
                v.visited = true
                v.accDist = 0
                v.prev = start
            } else {
                remainVrtxs.add(v)
                v.visited = false
                v.accDist = distTbl[vid_start][v.vid]
                v.prev = start } }
        while (!remainVrtxs.isEmpty()) {
            minAccDist = Int.MAX_VALUE / 2 // to prevent integer overflow
            minVID = -1
            minVrtx = null
            for (v in remainVrtxs) { vAccDist = v!!.accDist
                if (vAccDist < minAccDist) { minVID = v.vid
                    minAccDist = vAccDist
                    minVrtx = v }
            } // end for
            if (minVID == -1) { // if no vrtx is selected
                println("Error in selection of vertex with minimum AccDist")
                println("Graph is not fully connected !!")
                break
            } // end if
            selectedVrtxs.add(minVrtx)
            remainVrtxs.remove(minVrtx)
            minAccDist = minVrtx!!.accDist
                    for (v in remainVrtxs) {
                        /* edge relaxation */
                        if (v!!.accDist > minAccDist + distTbl[minVID][v.vid]) { v.accDist = minAccDist + distTbl[minVID][v.vid]; v.prev = minVrtx }
                    } // end for
            if (minVrtx.equals(dest)) { // if reached to the destination
                break }
        } // end while
        path.clear()
        path.add(dest)
        var v: Vertex? = dest
        var prvVrtx: Vertex
        while (!v!!.equals(start)) { v = v.prev; path.add(0, v) }
        return path
    }
    fun _DAG_traverse(v: Vertex?) {
        for (we in v!!.getWeightedEdges()) {
            val we_dest = we.getDest()
            if (we_dest!!.accDist <= v.accDist + we.getWeight()) {
                continue }
            we_dest.accDist = v.accDist + we.getWeight()
            we_dest.prev = v
            println("update %s, prev(%s), accDist (%d)" .format(we_dest.getName(), v.getName(), we_dest.accDist))
                    /* we_dest's accDist is updated, so children must be updated also */
                    _updateChildren(we_dest)
                    _DAG_traverse(we_dest)
        }
    }
    fun _updateChildren(v: Vertex?) {
        for (cv in v!!.children) {
            if (cv.accDist > v.accDist + distTbl[v.vid][cv.vid]) {
                cv.accDist = v.accDist + distTbl[v.vid][cv.vid]
                cv.prev = v
                println("update %s, prev(%s), accDist (%d)" .format(cv.getName(), v.getName(), cv.accDist))
                _updateChildren(cv)
            }
        }
    }
    fun DAGShortestPath(vrtx_start: Vertex?, vrtx_dest: Vertex): List<Vertex>? {
        val path = ArrayList<Vertex>()
        val dest_reached = false
        if (vrtx_dest.equals(vrtx_start)) {
            path.add(vrtx_dest)
            return path
        }
        for (v in vrtxArray) {
            if (v.equals(vrtx_start)) { v.accDist = 0; v.prev = vrtx_start }
            else { v.accDist = Int.MAX_VALUE / 2 // as infinitive, to prevent integer overflow
                v.prev = null
            }
            v.visited = false
        }
        _DAG_traverse(vrtx_start)
        /* for debugging purpose */
        System.out.printf("Accumulated dist : \n")
        for (v in vrtxArray) { print("(%s:%3d, prev:%s) ".format(v.vname, v.accDist, v.prev!!.getName())) }
        println()
        path.clear()
        path.add(vrtx_dest)
        var v: Vertex? = vrtx_dest
        while (!v!!.equals(vrtx_start)) { v = v.prev
            if (v != null) { path.add(0, v) }
        }
        return path
    }
}


