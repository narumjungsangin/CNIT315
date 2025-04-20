/*
Name: Junsu Yoon
Email: yoon188@purdue.edu
TA: Zara Ghorrati
Lab Session: Thursday 730-930 am
Descritption: The calculator to calculate the area of farm and area that could be covered by the sprinkler
*/
#include <stdio.h>
#include <math.h> //use math for pi

int main() {
    int gostop = 1;
    int iteration = 0;

    while (gostop == 1){
	printf("Do you want to calculate farm size output? If yes, press 1, if no, press 2");
	scanf("%i", &gostop);
	int count = 0;
	
	if (gostop == 2){
		printf("You have iterated %i times\n",iteration);
		break;
	}
	    
	    
	int size = 999; //initial size of the input inorder to prevent bug
	
	//input of the dimention
	printf("Please enter the number Dimention of the farm");
	scanf("%i", &size);
	
	//the systen would continuously ask for input if the input is not in range of 1000 feet and half a mile
	//1mile = 5280 feet
	while (size < 1000 || size > (5280/2)){
	    printf("Please enter the number below half a mile and over 1000 feet\n");
	    scanf("%i", &size);
	}
	
	//required calculation equations
	float pi = M_PI;
	float radius = size / 2;
	float circumfrance = 2 * pi * radius;
	float water_area = pi * radius * radius;
	float farm_area = size * size;
	float no_water = farm_area - water_area;
	float req_water = water_area * 0.17;
	float speed = circumfrance / 18;
		
	//output of the program
	printf("Area getting watered is %lf\n",water_area);
	printf("Area not getting watered is %lf\n",no_water);
	printf("Area getting watered is %lf\n",req_water);
	printf("Speed of sprinkler is %lf\n",speed);
	
	iteration ++;
	printf("You have iterated %i\n",iteration);
	gostop = 1;
    }
    printf("Program ended\n");
    
    
    return 0;
}
