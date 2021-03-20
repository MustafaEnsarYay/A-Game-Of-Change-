

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum status  {Continue , Won , Lost};

int rolldice (void);
int main( void) {
	
int sum;
int point;


enum status gamestatus;

srand( time( NULL ));

sum = rolldice();


	switch( sum){
	
		case 7: 
		case 11:
		
			gamestatus =  Won;
			break;
	
		case 2:
		case 3:
		case 12:
			gamestatus = Lost;
			break;
		
	
		default:
			gamestatus = Continue;
			point = sum;
			printf("Point is %d\n",point);
			break;
	
	}

	
	while(Continue == gamestatus){
		
		sum = rolldice();
		
		if( sum == point){
			gamestatus = Won;
		}
		else{
			if( 7 == sum ){
				gamestatus= Lost;
			}
		}	
	}
		
		
	if( Won == gamestatus){
		puts("Player wins!!!");
	}	
	else{
		puts("Player Lost!!!");
	}
	
	
}

int rolldice( void)
{
	int die1;
	int die2;
	int worksum;
	
	die1= 1 + ( rand() %6 );
	die2= 1 + ( rand() %6 );
	worksum= die1+die2;
	
	printf("Player diced %d + %d = %d \n",die1,die2,worksum);
	
	return worksum;
	
}
