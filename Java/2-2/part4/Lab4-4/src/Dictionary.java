class Dictionary {
    private static String [] kor = {"사랑", "아기", "돈", "미래", "희망"};
    private static String [] eng = {"love", "baby", "money", "future", "hope"};
    public static String kor2eng(String word){
        int i;
        for(i=0; i<kor.length; i++) if(word.equals(kor[i])) break;
        if(i==kor.length) return word+"는 저의 사전에 없습니다.";
        else return kor[i] + " -> " + eng[i];
    }
}