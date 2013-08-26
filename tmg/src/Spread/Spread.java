package Spread;

/**
 * Created with IntelliJ IDEA.
 * User: rotten
 * Date: 8/25/13
 * Time: 12:21 PM
 * To change this template use File | Settings | File Templates.
 */
public class Spread {


     public static void main(String[] args)
     {

         TimeSeries tree = new TimeSeries();
         TimeSeries tree2 = new TimeSeries();

         tree.setValue(0, 1250.00);
         tree.setValue(4, 1275.00);
         tree.setValue(15, 1275.00);
         tree.setValue(230, 1274.00);
         tree2.setValue(0, 1680.50);
         tree2.setValue(10, 1682.00);
         tree2.setValue(30, 1679.50);
         tree2.setValue(198,1679.75);


         TimeSeries spread = new TimeSeries();

         spread.getSpread(tree,tree2);

     }






}
