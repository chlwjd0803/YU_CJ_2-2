public class Km2Mile extends Converter {

    public Km2Mile(double ratio){
        this.ratio = (double)ratio;
    }

    @Override
    public double convert(double src){
        return (double)src / ratio;
    }

    @Override
    public String getSrcString(){
        return "Km";
    }

    @Override
    public String getDstString(){
        return "Mile";
    }

    public static void main(String[] args){
        Km2Mile k = new Km2Mile(1.6);
        k.run();
    }
}
