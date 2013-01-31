


object App {
  def main(args: Array[String]) {
    println("xxxxxxxxx")
    val b = 3 t2 3
    println(b);
  }
  implicit def calresult(i: Int): CalResult = new CalResult(i)

  class CalResult(i: Int) {
    def t(j: Int) = j * i
    def t2(j: Int)  = i * j *2
    def a(str: String) = str.toLowerCase
  }
}
