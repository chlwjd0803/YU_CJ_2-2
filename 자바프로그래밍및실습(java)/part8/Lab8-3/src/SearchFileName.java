import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.util.ArrayList;

public class SearchFileName {
    private File file;
    private ArrayList<String> a = new ArrayList<String>();


    private boolean store(){
        var sc = new Scanner(System.in);
        System.out.print("대상 파일명 입력 : ");
        String path = sc.next();

        try{
            file = new File(path);
            var fsc = new Scanner (new FileReader(file));
            int lineNumber = 1;
            while(fsc.hasNext()){
                String line = fsc.nextLine();
                a.add((lineNumber++) + " : " + line);
            }
            fsc.close();
        } catch (FileNotFoundException e) {
            System.out.println("파일을 읽어오지 못하였습니다. ");
            return false;
        }
        return true;
    }

    private void search(){
        var sc = new Scanner(System.in);
        while(true){
            System.out.print("검색할 단어나 문장 : ");
            String str = sc.next();
            if(str.equals("그만")) return;

            boolean notFound = true;

            for(int i=0; i<a.size(); i++) if(a.get(i).contains(str)){
                System.out.println(a.get(i));
                notFound = false;
            }
            if(notFound) System.out.println(str + "이 포함된 소스코드 라인이 존재하지 않습니다.");
        }
    }

    public void run(){
        if(store()) search();
        System.out.println("종료합니다.");
    }
}
