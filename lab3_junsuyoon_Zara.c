/*
Name: Junsu Yoon
Email: yoon188@purdue.edu
TA: Zara Ghorrati
Lab Session: Thursday 730-930 am
Descritption: Diffrent kind of recursion functions
*/
#include <stdio.h> 
#include <string.h> // Calculate String length
#include <stdbool.h> // Determine Boolean to end program

//The Factorial code use recursion to calculate
int factorial(int n)
{
    if (n==0)
        return 1; //base case
    else
        return n * factorial(n - 1);
}

//Hanoi function use recursion to search the plate movement
void runHanoi(int n, char x, char y, char z)
{
    if (n == 1)
        printf("from %c to %c\n", x, z);
    else
    {
        runHanoi(n-1,x,z,y);
        runHanoi(1,x,y,z);   //base case
        runHanoi(n-1,y,x,z);
    }
}

//Reverse function use recusion to change the order for char
void reverse(char n[], int end)
{
    if (end < 0)
        return; //base case
        
    printf("%c", n[end]);
    reverse(n, end - 1);
}

//Main fuction. It reads user inputs and move to respective function to do diffrent actions
int main() {
  int menu = 0; //reads user options
  int count = 0;
  bool exit = false;
  while(exit == false){
      printf("\nMain Menu\n");
       printf("1. Factorials\n");
       printf("2. Towers of Hanoi\n");
       printf("3. Reversing a string\n");
       printf("4. exit\n");
       scanf("%i", &menu);
   switch (menu){
       //menu options
       
        //1st option: factorial
       case 1: {
           printf("Please enter the number you want to factorial\n");
           int x = 0;
           scanf("%i", &x);
           int result = factorial(x);
           printf("The result is %i\n",result);
           count = count + 1;
           break;
       }
       
       //2nd option: Tower of Hanoi
       case 2: {
           printf("2: Tower of Hanoi\n");
           printf("How many disks are in the Tower?\n");
           int c;
           scanf("%i", &c);
           runHanoi(c, 'a', 'b', 'c');
           count = count + 1;
           break;
       }
       
       //3rd option: Reverse
       case 3: {
          printf("3: Reverse\n");
          printf("Please enter the word you want to reverse\n");
           char n[100];
          scanf("%s", n);
          printf("The result: ");
          reverse(n, strlen(n) - 1);  
          count = count + 1;
          break;
       }
    
       //4th option: End Program
       case 4: {
       printf("You iterated %i times\n", count);
       printf("End the program\n");
       
       exit = true;
           break;
       }
       
       default: {
          printf("Wrong Input, please enter number between 1 to 4\n");
        break;
        }
   }
  }

   return 0;
}



