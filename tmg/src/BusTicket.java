/**
 * Created with IntelliJ IDEA.
 * User: rotten
 * Date: 8/22/13
 * Time: 3:16 PM
 * To change this template use File | Settings | File Templates.
 */
public class BusTicket {


    public boolean isLucky(int x[]){
        int A = 0;
        int B = 0;

        for (int i = 0; i < x.length;++i)
        {


            if (i < 3)
                A += x[i];
            else
                B += x[i];
        }

        if (A == B)
           return true;
        else
           return false;



    }



    public static void main (String[] args){

        int arr[] = {1,2,3,3,2,1};
        BusTicket a = new BusTicket();
        System.out.print(a.isLucky(arr));


    }


}
