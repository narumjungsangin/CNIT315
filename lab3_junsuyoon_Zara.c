/*
Name: Junsu Yoon
Email: yoon188@purdue.edu
TA: Zara Ghorrati
Lab Session: Thursday 730-930 am
Descritption: Diffrent kind of recursion functions
*/
#include <stdio.h>

int factorial(int n)
{
    if (n==0)
    return 1;
    else
    return n * factorial(n - 1);
}


void runHanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
    //printf...
    }
    else
    {
    runHanoi(n-1,x,z,y);
    runHanoi(1,x,y,z);
    runHanoi(n-1,y,x,z);
    }
}


void reverse (string n){
    
    reverse n;
    return n;
    
}


int main() {
	while (1){
	int menu;
	printf("Main Menu\n");
	printf("1. Factorials\n");
	printf("2. Towers of Hanoi\n");
	printf("3. Reversing a string\n");
	printf("4. exit\n");
	scanf("%i", &menu);
    
	if (menu ==1) {
    	printf("Please enter the number you want to factorial\n");
    	int x = 0;
    	scanf("%i", &x);
    	int result = factorial(x);
    	printf("The result is %i\n",result);
	}
    
	else if (menu == 2) {
    	printf("2\n");
	}
    
	else if (menu == 3) {
    	printf("3\n");
	}
    
	else if (menu == 4) {
	printf("End the program\n");
    	break;
	}

    
	}

	return 0;
}
