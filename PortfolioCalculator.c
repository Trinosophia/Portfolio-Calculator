#include <stdio.h>
#include <ctype.h>
void printAssetName(char assetName[]);

void main() {
    char assetName[35]; continue[3];
    int count;
    double buyPrice, sellPrice, avgBuyPrice, totalValue, quantity, netProfit;

    printf("Enter the name of the asset you purchased.");
    fgets(assetName, sizeof(assetName),stdin);
    fflush(stdin);

    while(true){
    printf("Enter the purchase price and the sell price of this asset.\n");
    scanf("%lf", &buyPrice);
    scanf("%lf", &sellPrice);
    printf("How many did you purchase?");
    scanf("%lf", &quantity);
    totalValue += buyPrice * quantity;
    quantity += quantity; 
    netProfit += sellPrice - buyPrice;
    count++;
    // printf("Is that everything?");
    // fgets(continue, sizeof(assetName),stdin);
    // if(continue=="yes")
    //     false;
        
    
    }

    printf("%d %lf %lf %lf", count, totalValue, quantity, netProfit);

    
    printf("You entered %0.2lf and %0.2lf\n", buyPrice, sellPrice);

    // printf("\nYou entered: %c%s\n", toupper(assetName[0]), assetName+1);
    
    printAssetName(assetName);
 
}

void printAssetName(char assetName[]){
       for(int i=0; assetName[i]!='\0'; i++){
        if(i==0){
            printf("%c",toupper(assetName[0]));
        }
        else if(assetName[i]==' '){
            printf(" %c",toupper(assetName[i+1]));
            i++;
        }
        else{
            printf("%c", assetName[i]);
        }
}
}