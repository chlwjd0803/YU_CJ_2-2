import java.io.File


//모두 대문자로 출력이 되는걸 확인
fun processInput(inputLines: List<String>): List<String> {
    // Example processing: Capitalize each line
    return inputLines.map { it.toUpperCase() }
}

fun writeOutput(outputFile: String, lines: List<String>) {
    File(outputFile).bufferedWriter().use { out ->
        lines.forEach { line ->
            out.write(line)
            out.newLine() }
    }
}

fun main() {
    val inputFile = "input.txt"
    val outputFile = "output.txt"
    // Read input from the file
    val inputLines = File(inputFile).readLines()
    print("inputLines = \n")
    for (str_line in inputLines) {
        print(" %s\n".format(str_line))
    }
    // Process the input
    val processedLines = processInput(inputLines)
    // Write the processed data to the output file
    writeOutput(outputFile, processedLines)
    println("Data has been processed and written to $outputFile")
}