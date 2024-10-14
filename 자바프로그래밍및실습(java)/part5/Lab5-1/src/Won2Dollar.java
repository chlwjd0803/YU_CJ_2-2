public class Won2Dollar extends Converter {

    public Won2Dollar(double ratio) {
        this.ratio = (double)ratio;
    }

    @Override
    public double convert(double src){
        return (double)src / ratio;
    }

    @Override
    public String getSrcString(){
        return "원";
    }

    @Override
    public String getDstString(){
        return "달러";
    }

    public static void main(String[] args){
        Won2Dollar w = new Won2Dollar(1350);
        w.run();
    }
}
