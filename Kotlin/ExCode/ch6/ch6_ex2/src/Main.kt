import MyKotlinClass.CityPair
import java.io.File
import java.util.*

fun fget_InterCityDistMap( fname : String) : HashMap<CityPair, Int> {
    var hmap_ICD = HashMap<CityPair, Int>();
    val fin = Scanner(File(fname));
    var city_1 : String; var city_2 : String
    var dist : Int
    while(fin.hasNext()) {
        city_1 = fin.next();
        city_2 = fin.next();
        dist = fin.nextInt();
        hmap_ICD.put(CityPair(city_1, city_2), dist);
        hmap_ICD.put(CityPair(city_2, city_1), dist);
    }
    return hmap_ICD;
}

fun main(args: Array<String>) {
    val fname_ICD = "interCityDist.txt";
    var hmap_ICD : HashMap<CityPair, Int> = fget_InterCityDistMap(fname_ICD);
    var size = hmap_ICD.size;
    print("hmap_ICD (size = %d) = %s\n".format(size, hmap_ICD))
    var hmap_ICD_keys : Set<CityPair> = hmap_ICD.keys;
    print("hmap_ICD_keys = %s\n".format(hmap_ICD_keys))
    var test_cityPairs = arrayOf<CityPair> (CityPair("SL", "CC"), CityPair("CC", "SL"))
    for (tst_cp in test_cityPairs) {
        if (hmap_ICD.containsKey(tst_cp)) {
            var dist = hmap_ICD.get(tst_cp);
            System.out.printf("Distance of %s = %d\n", tst_cp, dist);
        } else {
            System.out.printf("key %s is not included in hashMap !!\n", tst_cp);
        }
    }
}