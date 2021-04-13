/* Christian Saputro
 * February 13, 2021
 * CIS 2107
 * Lab #3 ATM
 * to create a simple atm machine for user
 *  */
#include <stdio.h>
#include <stdlib.h>

// global variable to use in every function
int i;
int updatedBal;
float totalBal = 5000;

// creates a function for login and inputting pin which is 3014
int login()
{
    int PIN; // variable to hold pin

    for (i = 0; i < 3; i++) //for loop if wrong input = 3 then terminates the program
    {

        printf("Please enter your PIN number: \n");
        scanf("%d", &PIN);

        if (PIN == 3014) //if correct pin inserted, moves on to the next function
        {
            return 1;
        }
        else
        {
            printf("Incorrect PIN, please try again\n");
        }
    }
    if (i == 3) //if pin is inputted incorrectly 3 times, logs out
    {
        printf("You entered the pin incorrectly 3 times, logging out...");
        exit(0);
    }
    return 1;
}

int deposit() //function for deposit
{
    //variables to hold things in this function
    int depAmount;

    for (i = 0; i < 3; i++) //for loop if wrong input = 3 then terminates the program
    {
        printf("Enter the amount that you would to deposit, No coins will be accepted!: \n");
        scanf("%d", &depAmount);
        if (i == 3) //if wrong input 3 times, terminates the program
        {
            printf("Error: Logging out...\n");
            exit(0);
        }
        if (depAmount != 0 && depAmount % 5 == 0) //if deposit is more than $0 then continues the program
        {
            updatedBal = depAmount + totalBal; //calculates after deposit to update the new balance
            totalBal = updatedBal;

            printf("Your new balance is $%.2f\n", totalBal);
            return (totalBal);
        }
        else if (depAmount > 10000) // deposit limit is 10,000 per day
        {
            printf("The limit amount to deposit is $10,000 a day. \n");
        }
        else //if input is < 0 prints this out
        {
            printf("Invalid amount");
        }
    }
}

int withdrawal() //functions to withdraw money
{
    int takeAmount; //variable to use in this function

    for (i = 0; i < 3; i++) //for loop if wrong input = 3 then terminates the program
    {
        printf("Please enter the amount of money you would like to withdraw (cannot withdraw coins): $\n");
        scanf("%d", &takeAmount);
        if (i == 3) //if wrong input 3 times, terminates the program
        {
            printf("Error: Logging out...\n");
            exit(0);
        }
        if (takeAmount != 0 && takeAmount % 20 == 0) //if amount is > 0 then run this program
        {
            updatedBal = totalBal - takeAmount; //calculates after witdraw to update the new balance
            totalBal = updatedBal;
            printf("Your new balance is $%.2f\n", totalBal);
            return (totalBal);
        }
    }
}

int returnToMenu() //functions to return to the menu after transaction
{
    int choice; //variable for this function

    printf("would you like to make any other transaction? Please press 1 for yes, 2 for no\n");
    scanf("%d", &choice);
    if (choice == 1) //if yes go run homepage again
    {
        homePage();
    }
    else if (choice == 2) //if no, ask to print receipt
    {
        printf("Would you like a receipt? 1: Yes, 2: No\n");
        scanf("%d", &choice);
        if (choice == 1) //choice one prints receipt and prints exit message
        {
            printf("Printing receipt...\n");
            printf("Thank you for using us, we will be watching every dollar you spent. Have a nice day!");
            exit(0);
        }
        else //if user press 2 then just prints out exit message
        {
            printf("Thank you for using us, we will be watching every dollar you spent. Have a nice day!");
            exit(0);
        }
    }
    else //if user put something thats not 1 or 2 then runs it again
    {
        printf("please make a selection of 1 or 2 only\n");
        returnToMenu();
    }
}

int homePage() //homepage function where it displays the main menu after logging in
{
    int selection; //variable to hold the selection in this function

    printf("Welcome to the Bank of Look Behind you! Please make a selection: \n");
    printf("1 to view your balance\n");
    printf("2 to deposit\n");
    printf("3 to withdraw\n");
    printf("4 to exit\n");
    scanf("%d", &selection);
    if (selection == 1) //1st selection takes them to balance view
    {
        printf("Your balance is: $%.2f\n", totalBal);
        returnToMenu(); //runs the menu back
    }
    else if (selection == 2) //2nd selection takes them to deposit menu
    {
        deposit();
        returnToMenu(); //runs the menu back
    }
    else if (selection == 3) //3rd selection takes them to withdrawal menu
    {
        withdrawal();
        returnToMenu(); //runs the menu back
    }
    else if (selection == 4) //4th selection exits and terminate the program
    {
        printf("Thank you for using us, we will be watching every dollar you spent. Have a nice day!");
        exit(0);
    }
    else
    {
        printf("Please select 1-4, no other numbers will be accepted\n");
        homePage(); //runs the home page function back
    }
}

//runs the program
int main()
{
    login();
    homePage();
    return 0;
}