class Grade {
    private int mth;
    private int sci;
    private int eng;

    //아래 경우는 private 를 제외하고 모두 가능
    public Grade(int mth, int sci, int eng) {
        this.mth = mth;
        this.sci = sci;
        this.eng = eng;
    } //intellij 우클릭 생성으로 하면 알아서 생성자 만들어줌

    public double average(){return (mth + sci + eng) / 3;}
}