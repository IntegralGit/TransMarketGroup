/**
 * Created with IntelliJ IDEA.
 * User: rotten
 * Date: 8/22/13
 * Time: 3:38 PM
 * To change this template use File | Settings | File Templates.
 */





public class Pisa
{




     public static void main(String[] args) {
    //I worked with GPS data at Nokia and well
    //this is a wierd problem...
    //Iv'e attached a png done in ps paint to do the job justice.
    //find midpoint of top and bottom of tower
    //then connect the points to find the distance
    //any place a new balcony is placed will touch the reference line

    double lat = 0.00;
    double lon = 0.00;

    /*
    Making Pisa plane with dummy variables
    */
    Point x_pisa = new Point(lat,lon);
    Point y_pisa = new Point(lat,lon);
    Point z_pisa = new Point(lat,lon);
    Plane pisa = new Plane(x_pisa,y_pisa,z_pisa);//3point plane of tower

    /*
    Making Balcony plane with dummy variables
    */
    Point x_balcony = new Point(lat,lon);
    Point y_balcony = new Point(lat,lon);
    Point z_balcony = new Point(lat,lon);
    Plane balcony = new Plane(x_balcony,y_balcony,z_balcony);//3point plane of balcony


    if(checkIfPerpendicular(pisa,balcony))
        System.out.println("Balcony is Perpendicular");
    System.out.println("Balcony is Not Perpendicular");



     }

    public static boolean checkIfPerpendicular(Plane a,Plane b)
    {
        if( a.getX()*b.getX()+a.getY()*b.getY()+a.getZ()*a.getY() == 0)
            return true;
        else
            return false;
    }
}


