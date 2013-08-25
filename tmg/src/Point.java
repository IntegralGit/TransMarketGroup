/**
 * Created with IntelliJ IDEA.
 * User: rotten
 * Date: 8/25/13
 * Time: 11:28 AM
 * To change this template use File | Settings | File Templates.
 */
public class Point
{
    private double _lat , _lon;

    public Point ( double lat, double lon )
    {
           /* _radius = Math.sqrt ( Math.pow(x,2) + Math.pow (y,2) ) ;
            _alpha = ( ( Math.atan (y/x) ) * 180 ) / Math.PI;*/

        _lat = lat;
        _lon = lon;
    }



    public double getLat()
    {
        return _lat;
    }
    public double get_lon()
    {
        return _lon;
    }
    public double getAngle(Point a,Point b)
    {
        double lat1 = Math.toRadians(a.getLat());
        double lat2 = Math.toRadians(b.getLat());
        double lon1 = Math.toRadians(a.get_lon());
        double lon2 = Math.toRadians(b.get_lon());

        double dy = lat2 - lat1;
        double dx = Math.cos(Math.PI/180*lat1)*(lon1 - lon2);
        double angle = Math.atan2(dy, dx);


         return angle;

    }
    public double getDistance(Point a,Point b)
    {
        double R = 6371; // km


        double dLat = Math.toRadians(b.getLat() - a.getLat());
        double dLon = Math.toRadians(b.get_lon() - b.get_lon());
        double lat1 = Math.toRadians(a.getLat());
        double lat2 = Math.toRadians(b.getLat());

        double aa = (Math.sin(dLat/2) * Math.sin(dLat/2) +  Math.sin(dLon/2) * Math.sin(dLon/2) * Math.cos(lat1) * Math.cos(lat2));
        double c = 2 * Math.atan2(Math.sqrt(aa), Math.sqrt(1-aa));
        double d = R * c;


        return d;
    }



}