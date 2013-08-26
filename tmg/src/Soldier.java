
/**
 * Created with IntelliJ IDEA.
 * User: Piotr
 * Date: 8/22/13
 * Time: 4:02 PM
 * To change this template use File | Settings | File Templates.
 */
public class Soldier {

    //The missing soldier is the Spy!

    public int isSpy(int x[]){

     int spy = 0;

     for (int i = 0; i < x.length;++i){

        if (x[i] == 0)
           spy = i+1;
     }

     return spy;

    }

    public int[] fillArray(int spy){   //does not insert the spies patch number
                                       // if spy = 0 just fills array 1-100
        int[] arr = new int[100];
        int x = 0;

        if (spy == 0){
            for (int i = 1; i <= 100;++i){
                arr[x] = i;
                x++;
            }
        }else
            for (int i = 1; i <= 100;++i){
                if(i != spy)
                    arr[x] = i;
                 x++;
            }
        return arr;
    }




    public static void main (String[] args){

        Soldier x = new Soldier();
        int[] y = x.fillArray(10);



//        for (int i = 0; i < y.length; ++i){
//
//           System.out.print(y[i] + "\n");
//
//
//        }

        int spy = x.isSpy(y);
        System.out.print(spy);



    }

}
