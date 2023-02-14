import java.util.Scanner;


public class PortfolioCalculator {
    private static double[] hodlArray = new double[5];
    private static double[] sellArray = new double[5];
    public static void main(String[] args){

        String initCoin, newCoin;
        double initPrice, initNumCoins, initFiatValue, exitPrice, exitFiatValue;
        double newPrice, newNumCoins, newFiatValue, breakEven, percentLoss, percentGain, percentChange;
        newPrice = newNumCoins = newFiatValue = breakEven = percentLoss = percentGain = 0;
        Scanner kb = new Scanner(System.in);
        System.out.println("What asset did you purchase? (i.e. Bitcoin, Ethereum, etc.)");
        initCoin = kb.nextLine();
        System.out.println("How many units of this asset did you purchase?");
        initNumCoins = kb.nextDouble();
        //hodlArray[0] = initNumCoins;
        System.out.println("At what price value did you purchase these assets?");
        initPrice = kb.nextDouble();
       // hodlArray[1] = initPrice;

        initFiatValue = initNumCoins * initPrice; 
        //hodlArray[2] = initFiatValue;
        
        System.out.println("What price will you exit the market?");
        exitPrice = kb.nextDouble();
        exitFiatValue = exitPrice * initNumCoins;
        System.out.println("Current fiat value: " + exitFiatValue);
         
        percentChange = ((exitPrice - initPrice)/(initPrice)) * 100;

        if(percentChange < 0){
        percentLoss = percentChange / -1;
        System.out.printf("%.2f%% loss", percentLoss);
        }
        else if(percentChange > 0){
        percentGain = percentChange;
        System.out.printf("%.2f%% gain", percentGain);
        }
        else{
        System.out.println("0% gain");
        }
        System.out.println();
        displayTable(initCoin, initPrice, initNumCoins, initFiatValue);
        
    
}

public static void displayTable(String initCoin, double initPrice, double initNumCoins, double initFiatValue){

    
        System.out.println("+--------------------+----------+----------+----------+----------+");
        System.out.print("|");
        int spacing = (20 - initCoin.length())/2;
        for(int i = 0; i<spacing; i++)
            System.out.print(" ");
        System.out.print(initCoin);
        for(int i = 0; i<spacing; i++)
            System.out.print(" ");
        System.out.print("|");
        System.out.println();
        System.out.println("+--------------------+----------+----------+----------+----------+");
    }

}

