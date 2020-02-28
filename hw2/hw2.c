#include <stdio.h>
#include<time.h>
#include<stdlib.h>


int make_a_guess (int , int *  , int * );
void menu();
void show_scores(int , int );
void draw_hourglass (int );
void draw_mountain_road (int , int );

int main()
{
	
	srand(time(NULL));						//to use the rondom function in the whole program
	menu();




	return 0;
}

void menu()
{	
	int try_trial=0;
	
	int trial=0;				//for lucky number games    
	int trial_counter=1;		//to count the trials
	int min=1, max=1024;		
	int entered_number;  
	int score_human=0,score_program=0;

	int height;    

	int length,max_radius;       //For part 4(mountain road)               
	

	while(entered_number!=4)
	{
		printf("\n\n\n***** MENU *****\n");
		printf("1. Play Lucky Number\n2. Draw Hourglass\n3. Draw Mountain Road\n4. Exit\n");
		printf("\nChoice:");
		scanf("%d",&entered_number);
		trial=0;						//to again use the case 1's while loop

		switch(entered_number)
		{
			
			case 1:		


						while(trial!=-1 && trial_counter<11)				//Control to whether random number equal to trial number and trial input's number
						{
						printf("(Trial : %d)",trial_counter );
						trial=make_a_guess (trial,&min,&max);				 // I used the pointer for change max min values 

						trial_counter++;
						}

						if (trial_counter>10 && trial!=-1)					//if trial will be more than ten and doesnt trial equal to -1 program wins
						{
							score_program++;						//trial doesnt be equal -1 to program wins because maybe last trial is correct 

						}
						else
							score_human++;
						
						trial_counter=1;							  //for get in the other loops
						show_scores(score_human, score_program);
						min=1, max=1024;  							//for reset the max. and min. points


				break;
			case 2:	
					printf("Input the height: ");
					scanf("%d",&height);
					printf("\n\n\n");
					draw_hourglass (height);



				break;
			case 3:


					printf("Input length: ");
					scanf("%d",&length);
					printf("Input max_radius: ");
					scanf("%d",&max_radius);
					draw_mountain_road (length,max_radius);


				break;

			case 4:


				break;

			default:
				printf("Error Invalid Input\n\n\n");

		}
	}

}

int make_a_guess (int trial, int *min, int *max)
{	
		
		int LN;

		
		if(trial==0)	
			LN=rand()%1024+1; // for use 1 time to random function
		
		
		int distance;					//to calculate the distance between LN and guess number
		printf("Make a make_a_guess between %d and %d:",*min,*max);
		scanf("%d",&trial);
		distance=abs(LN-trial);    //distance must be positive
	
		if (LN!=trial && (*max-trial>=trial-*min) && trial>*min && trial<LN)   
		{
			*min=trial;
		}

		else if (LN!=trial && (*max-trial<trial-*min) && trial<*max && trial>LN)
		{
			*max=trial;
		}

		else if (LN==trial)
		{
			trial==-1;				//to define Ln equal to trial
		}

		else if (trial<LN && trial>*min )
		{
			*min=trial;
		}
		else if(trial>LN && *max>trial)
			*max=trial;



		
		if (distance<1024 && distance>=512)
		{
			printf("Distance: 10.\n");
		}

		else if (distance>=256)
		{
			printf("Distance: 9.\n");
		}

		else if (distance>=128)
		{
			printf("Distance: 8.\n");
		}
		else if (distance>=64)
		{
			printf("Distance: 7.\n");
		}
		else if (distance>=32)
		{
			printf("Distance: 6.\n");
		}
		else if (distance>=16)
		{
			printf("Distance: 5.\n");
		}
		else if (distance>=8)
		{
			printf("Distance: 4.\n");
		}
		else if (distance>=4)
		{
			printf("Distance: 3.\n");
		}
		else if (distance>=2)
		{
			printf("Distance: 2.\n");
		}
		else if (distance>=1)
		{
			printf("Distance: 1.\n");
		}
		else if (distance==0)
		{
			
			printf("Distance: 0. You win!\n\n\n");
			trial=-1;														//to define Ln equal to trial
		}

		

	return trial;

}
void show_scores(int score_human,int score_program)
{
	printf("\n\n                 Your score= %d  Program score= %d \n",score_human, score_program);
} 


void draw_hourglass (int height)

{	
	int flag=0;							//for while loop
	int ask;
	int b,i,j;							//draw to the pattern, loops  
	

	while(flag ==0)
	{
		if (height%2==0)
		{
			printf("Warning, Wrong Input !\n");
			printf("1. New Input\n2. Exit\n");	
			scanf("%d",&ask);
			if (ask==1)
			{	
				printf("Input the height: ");
				scanf("%d",&height);
				printf("\n\n\n");

			}
			else if(ask==2)
				flag++;

			else
				printf("Wrong Input again!\n");
		}
		else
		{
			height=height/2+1;							// to write the half of pattern

			for (int i = 1; i <= height; ++i)
			{
				for (b = 1; b <=i-1 ; ++b)
				{
					printf(" ");
				}
				for (j = height*2-(2*i-1); j >0 ; --j)
				{
					printf("*");
				}

				printf("\n");
			}

			for (int i = 1; i < height; ++i)
			{
				for (b = 0; b < height-i-1; ++b)
				{
					printf(" ");
				}

				for (j =1 ; j <2+2*i; j++)
				{
					printf("*");
				}
				printf("\n");
			}


			flag++;											//to quit while loop

		

		}

	}
		
}


void draw_mountain_road (int length, int max_radius)
{
	int radius;
	int mainloop, i,j,k,space;

	max_radius=max_radius+1;											//i added +1 because radius include max radius

	for (mainloop = 1; mainloop <=length ; mainloop++)					// The main loop arrange mountain road lenght
	{	

		radius=rand()%max_radius;

		if (radius==0)													//if there is no radius road will be straight		
		{
			for (space = max_radius+1; space >0 ; --space)
			{
				printf(" ");
			}
			printf("|");												//the middle of the road
			printf("\n");
		}


		else
		{
		
			if (mainloop%2==1)												// This ifcase arrange the series of road
			{
				for (j=0,i=radius; i >0 ; i--,j++)							//i used the two parameter because radius should be stable
				{
					for (space = -j+max_radius; space >0; --space)			// i added the max. radius because of road may can exceed the border 
					{
						printf(" ");
					}
					printf("/");												//the first part of road
					printf("\n");
				}

				if (i==0)
				{
					for (space = max_radius-radius; space >0 ; --space)
					{
						printf(" ");
					}
					printf("|");												//the middle of the road
					printf("\n");
				}


				for (i = radius; i >0 ; --i)
				{
					for (space=max_radius-i+1; space >0 ; --space)				//+1 for arrange the pattern
					{
						printf(" ");
					}

					printf("\\");
					printf("\n");
				}
			}
			
			
			else if (mainloop%2==0)											//The second part of road (right way)
			{
				for (i = radius; i >0 ; --i)
				{
					for (space=max_radius+radius+1-i; space >0 ; --space)
					{
						printf(" ");
					}

					printf("\\");
					printf("\n");
				}


				if (i==0)
				{
					for (space = max_radius+radius+1; space >0 ; --space)
					{
						printf(" ");
					}
					printf("|");												//the middle of the road
					printf("\n");
				}

				for (i=radius; i >0 ; i--)
				{
					for (space = max_radius+i; space >0; --space)			// i added the max. radius because of road may can exceed the border 
				{
						printf(" ");
				}
					printf("/");												//the first part of road
					printf("\n");
				}
			}
		}

	}
}
