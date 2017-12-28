/**
 * the input of the number is: n
 * convertToTen run log10(n) and pows.
 * There fore, the averall running time is O(nlogn).
 */


#include <stdio.h>
#include <math.h>


/**
 * convertToTen is the function that takes the original base and returns the value for base 10.
 * @param num - the number we are given
 * @param originalBase - the old base
 * @return invalid (and 1) for not a legal input, otherwise the base we want.
 */
long convertToTen(int num, int originalBase)
{
    int index = 0;
    unsigned long theNewNum = 0;
    while (num > 0)
    {
        int remainder = num % 10;
        if (remainder >= originalBase) // checking legal input
        {
            printf ("invalid!!\n"); // illegal input
            return 1;
        }
        theNewNum += (num % 10) * powl(originalBase, index); // for legal input, converts it.
        num /= 10;
        index++;
    }
    return theNewNum;
}
/**
 * this function takes the converted base, and converts it to binary.
 * @param num - the number
 * @param newBase - the base we want to convert it to.
 * @return the converted number.
 */
unsigned long convertBaseFromTen(unsigned long num, int newBase)
{
    int index = 0;
    unsigned long theNewNum = 0;
    while (num > 0) // converting to the new num
    {
        theNewNum += ((num % newBase) *  powl(10 , index));
        num /= newBase;
        index++;
    }

    return theNewNum;
}
/**
 * we receive a number, an old base and a new base. We change it to the converted number base on the formulas given.
 * @return the converted number.
 */
int main()
{
    int originalBase;
    int newBase;
    int num;
    printf("ChangeBase");
    scanf("%d %d %d", &originalBase, &newBase, &num);
    unsigned long newNum = convertToTen(num, originalBase);
    unsigned long numberInNewBase = convertBaseFromTen(newNum, newBase);
    printf("%lu \n", numberInNewBase);
    return 0;
}