public class Player {
    public int rps;
    public String rps_str [] = {"none", "가위", "바위", "보"};

    public void setRps(int n){ rps = n; }

    public String getRps(){
        return rps_str[rps];
    }
}
