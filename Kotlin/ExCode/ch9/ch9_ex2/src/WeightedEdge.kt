package Graph

class WeightedEdge {
    //the class stores the edges of the graph
//the class stores the edges of the graph
    private var src: Vertex? = null
    private var dest: Vertex? = null
    private var weight = 0
    //creating a constructor of the class Edge
    constructor(src: Vertex?, dest: Vertex?, weight: Int) {
        this.src = src
        this.dest = dest
        this.weight = weight
    }
    override fun toString(): String {
        return src.toString() + "->" + dest
    }
    fun getSrcVID(): Int {
        return src!!.getVID()
    }
    fun getDestVID(): Int {
        return dest!!.getVID()
    }
    fun getDest(): Vertex? {
        return dest
    }
    fun getWeight(): Int {
        return weight
    }
}