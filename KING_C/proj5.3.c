/*
 * 3. Modify the broker.c program of Section 5.2 by making both of the follwing changes:
 * (a) Ask the user to enter the number of shares and the price per share, instead of
 *     the value of the trade.
 * (b) Add statements that compute the commission charged by a rival broker ($33 plus
 *     3 cents per share for fewer than 2000 shares; $33 plus 2 cents per shrare for
 *     2000 shares or more). Display the rival's commission as well as the commission
 *     chared by the original broker.
 */

#include <stdio.h>

int main(void)
{
   float commission, value;

   float rivalCommission;
   int numberOfShares;
   float pricePerShare;

   printf("Enter the number of shares: ");
   scanf("%d", &numberOfShares);
   printf("Enter the price per share: ");
   scanf("%f", &pricePerShare);

   value = (float)numberOfShares * pricePerShare;

   if (value < 2500.00f)
      commission = 30.00f + .017f * value;
   else if (value < 6250.00f)
      commission = 56.00f + .0066f * value;
   else if (value < 20000.00f)
      commission = 76.00f + .0034f * value;
   else if (value < 50000.00f)
      commission = 100.00f + .0022f * value;
   else if (value < 500000.00f)
      commission = 155.00f + .0011f * value;
   else
      commission = 255.00f + .0009f * value;

   if (commission < 39.00f)
      commission = 39.00f;

   // Compute the rival's commission
   if (numberOfShares < 2000)
      rivalCommission = 33.00f + .03f * numberOfShares;
   else
      rivalCommission = 33.00f + .02f * numberOfShares;

   printf("Original commission: $%.2f\n", commission);
   printf("Rival commission: $%.2f\n", rivalCommission);

   return 0;
}
