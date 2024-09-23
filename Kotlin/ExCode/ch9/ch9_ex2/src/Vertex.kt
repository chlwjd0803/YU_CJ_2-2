package Graph

class Vertex {
    var vname: String? = null //vertex name
    var vid = 0
    var wedges: MutableList<WeightedEdge> = ArrayList<WeightedEdge>()
    var children: List<Vertex> = ArrayList() // used in DAG
    var visited = false // used in Graph search
    var prev: Vertex? = null // used in Graph search
    var accDist = 0 // accumulated distance from source, used in Graph search
    var level = 0 // used in BFS
    //creating a constructor of the class Vertex /Node
    constructor(name: String?) // constructor
    {
        vname = name
        visited = false
        prev = null
        accDist = 0
    }
    fun getName(): String? {
        return vname
    }
    fun setVID(vid: Int) {
        this.vid = vid
    }
    fun getVID(): Int {
        return vid
    }
    fun addWeightedEdge(vrtx_dest: Vertex?, weight: Int) {
        val wedge = WeightedEdge(this, vrtx_dest, weight)
        wedges.add(wedge)
    }
    fun getWeightedEdges(): List<WeightedEdge> {
        return wedges
    }
    override fun toString(): String {
        return vname!!
    }
}