/**
 * Created with IntelliJ IDEA.
 * User: rotten
 * Date: 8/25/13
 * Time: 12:11 PM
 * To change this template use File | Settings | File Templates.
 */

import java.util.Map;
import java.util.TreeMap;
import java.util.NavigableMap;

public class TimeSeries {

    public double _price;
    public Integer _time;
    NavigableMap<Integer,Double> _value;

    public TimeSeries()
    {
           /* _radius = Math.sqrt ( Math.pow(x,2) + Math.pow (y,2) ) ;
            _alpha = ( ( Math.atan (y/x) ) * 180 ) / Math.PI;*/

    _value = new TreeMap<Integer,Double>();
    }

    public void setValue(Integer time, double price)
    {

        _value.put(time,price);



    }


    public TimeSeries getSpread(TimeSeries a,TimeSeries b)
    {
       TimeSeries x = new TimeSeries();
       int cap = 0;

       int aLast = a._value.lastKey();
       int bLast = b._value.lastKey();

       while(cap <= aLast)
       {
        //System.out.println(a._value.get(a._value.floorKey(cap)) + " --- "+ b._value.get(b._value.floorKey(cap)) +" == "+ cap);
        double spread = a._value.get(a._value.floorKey(cap)) - b._value.get(b._value.floorKey(cap));
        //System.out.println(spread);
        x.setValue(cap,spread);
        cap += 10;
       }
       //cap = cap + 10;
       x.printTimeSeries();
       return x;

    }

    public void printTimeSeries()
    {

        for (Map.Entry<Integer, Double> entry : this._value.entrySet())
        {
          System.out.println("TIME: "+entry.getKey()+ " ---- PRICE: "+ entry.getValue());

        }
    }
}







