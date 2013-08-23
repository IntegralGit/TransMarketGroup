/**
 * Created with IntelliJ IDEA.
 * User: rotten
 * Date: 8/22/13
 * Time: 4:47 PM
 * To change this template use File | Settings | File Templates.
 */
public class BondMath {
    //Zero coupon bond value = F / (1 + r)^t
    //F = face value of bond
    //r = rate or yield
    //t = time to maturity

    public double getRate(double facevalue,double cost,double maturity)
    {

        double r = 1-StrictMath.pow((facevalue/cost),(1.0/maturity));
        //System.out.print(r + "\n");
        return r;
    }

    public double getReturn(double facevalue,double offer,double maturity)
    {

        double bondreturn = facevalue/ StrictMath.pow(1 + getRate(facevalue,offer,maturity),maturity);
        return bondreturn;
    }


    public static void main(String[] args){

        double facevalue = 95.50;
        double offer     = 100.00;
        double maturity  = 153;

        double yearScale = maturity/365;

        BondMath x = new BondMath();
        double bondreturn = x.getReturn(facevalue,offer,yearScale);

        System.out.print(bondreturn );


    }

}
