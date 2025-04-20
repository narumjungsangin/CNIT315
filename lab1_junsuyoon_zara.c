/*
Name: Junsu Yoon
Email: yoon188@purdue.edu
TA: Zara Ghorrati
Lab Session: Thursday 730-930 am
Descritption: The calculator to calculate how many boxs users can put in an container and how much they would have to pay for it. 
*/
#include <stdio.h>
int main() {
    int box1_amount, box2_amount;
    int box1_volume = 1 * 1 * 1;
    int box2_volume = 1 * 2 * 2;
    int box1_price = 20;
    int box2_price = 35;
    int shipping_container = 40 * 8 * 8; 
    
    //Ask the user how many Type1 and Type 2 boxed they want to ship
    printf("How many Type 1 box do you want to ship?");
    scanf("%i", &box1_amount);
    
    int box1_totalSize = box1_amount * box1_volume;
    
    //After the user enters the Type 1 number of boxes, calculate the space remaining for Type 2 boxes and display to the user
    int space_before_box2 = shipping_container - box1_totalSize;
    if(space_before_box2 < 0){
    printf("There arn't enough space! Ending Program");
    return 0;
    }
    printf("There are %i square feets left for box 2\n",space_before_box2);
      
    //Calculate what is the max number of Type 2 boxes that you can store
    int howmany_for_box2 = space_before_box2 / box2_volume;
    printf("You can store %i more type 2 box\n",howmany_for_box2);
    
    printf("How many Type 2 box do you want to ship?");
    scanf("%i", &box2_amount);
    int box2_totalSize = box2_amount * box2_volume;
    
    //Calculate the total cubic footage for the boxed they want to ship
    int total_box = box1_totalSize + box2_totalSize;
    
    
     int unused_space = shipping_container - total_box;
    //Calculate the number of cubic feet available in the shipping container and display it for the user
    //After the Type 2 number of boxes is entered, show how much space in in remaining of the container
     
    
    //Show the total shipping cost of their boxes
    int total_price = box1_price * box1_amount + box2_price * box2_amount;
    
    //If the cubic footage is greater than the available space, then tell the user it is too large
    if (shipping_container < total_box) {
        printf("The amount of the total box does not fit in the shipping container!\n"); 
        return 0;
    }

    //Give $2 discount for any unnused space in the contaner show the discount to the user
    printf("Available number of cuibc feet in shipping container is %i\n",unused_space);
    int discount = 2 * unused_space;
    printf("You have used  %i\n",total_box);
    printf("You have been discounted $%i\n",discount);
    
    //Show total shipping cost with the discount
    total_price = total_price - discount;
    printf("Your total price is $%i\n",total_price);

    //end program
    printf("program ended...");
    return 0;
}
