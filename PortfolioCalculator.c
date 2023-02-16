#include <stdio.h>
#include <ctype.h>
#include <string.h>
void printAssetName(char assetName[]);
void printPortfolio(double avgBuyPrice, double avgSellPrice, double initialBalance, double currentBalance, double netProfit);

void main()
{
    char assetName[35];
    char resume = 'y';
    int count = 0;
    int cont = 1;
    double buyPrice, buyRunTotal, sellRunTotal, sellPrice, avgBuyPrice, avgSellPrice, initialBalance, totalQuant, quantity, netProfit, currentBalance = 0;

    printf("Enter the name of the asset you purchased.\n");
    fgets(assetName, sizeof(assetName), stdin);
    fflush(stdin);

    while (tolower(resume) == 'y')
    {
        printf("Enter the purchase price and the sell price of this asset.\n");
        scanf("%lf", &buyPrice);
        scanf("%lf", &sellPrice);
        buyRunTotal += buyPrice;
        sellRunTotal += sellPrice;
        printf("How many did you purchase?\n");
        scanf("%lf", &quantity);
        totalQuant += quantity;
        initialBalance += (buyPrice * quantity);
        if (sellPrice < buyPrice)
            currentBalance -= (sellPrice * quantity);
        else
            currentBalance += (sellPrice * quantity);
        count++;
        fflush(stdin);
        printf("Did you have another order to input? Please enter Y or N.\n");
        scanf("%c", &resume);
    }
    // printf("Buy Run Total: %lf\n", buyRunTotal);
    // printf("Sell Run Total: %lf\n", sellRunTotal);
    avgBuyPrice = buyRunTotal / count;
    avgSellPrice = sellRunTotal / count;
    netProfit += currentBalance - initialBalance;
    // printf("%d\n", cont);
    // printf("%c\n", resume);
    printAssetName(assetName);
    printPortfolio(avgBuyPrice, avgSellPrice, initialBalance, currentBalance, netProfit);

    // printf("You entered %0.2lf and %0.2lf\n", buyPrice, sellPrice);
    // printf("\nYou entered: %c%s\n", toupper(assetName[0]), assetName+1);
}

void printAssetName(char assetName[])
{
    for (int j = 0; j < strlen(assetName) + 3; j++)
    {
        printf("-");
    }
    printf("\n");

    for (int i = 0; assetName[i] != '\0'; i++)
    {
        if (i == 0)
        {
            printf("| %c", toupper(assetName[0]));
        }
        else if (assetName[i] == ' ')
        {
            printf(" %c", toupper(assetName[i + 1]));
            i++;
        }
        else if (assetName[i + 1] == '\0')
        {
            printf(" |\n");
        }
        else
        {
            printf("%c", assetName[i]);
        }
    }
    for (int k = 0; k < strlen(assetName) + 3; k++)
    {
        printf("-");
    }
    printf("\n");
}

void printPortfolio(double avgBuyPrice, double avgSellPrice, double initialBalance, double currentBalance, double netProfit)
{
    printf("Average Buy Price: $%0.2lf\n Average Sell Price: $%0.2lf\n Initial Investment: $%0.2lf\n Current Balance: $%.02lf\n Net Profit: $%.02lf\n", avgBuyPrice, avgSellPrice, initialBalance, currentBalance, netProfit);
}