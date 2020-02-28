#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum{	
	noone,cap,car
}player_type;

typedef enum{
	start,property,tax,punish
}block_type;

typedef struct 
{
	player_type type;
	int current_block_id;
	int owned_block_ids[11];
	int account;
	int turn_to_wait;
	char * name;
}player;

typedef struct{

	int block_id;
	char * name;
	int price;
	int rent;
	int rent_1;
	int rent_2;
	int rent_3;
	int house_price;
	int house_count;
	player owner;
	block_type type;

}block;
void sell_property(block [], player* );
void buy_property(block *,player *);
void init_the_board(block []);
void show_board(block [],player ,player );
void show_properties(block []);
void gameplay (block [],player , player);


int main(int argc, char const *argv[])
{	
	int i;
	srand(time(NULL));
	block board[20],*current_block;
	player player_one, player_two,*current_player;
	//*current_player=player_one;
	player_one.name="cap";
	player_two.name="car";
	player_one.turn_to_wait=0;
	player_two.turn_to_wait=0;
	player_one.account=15000;
	player_two.account=15000;
	player_one.current_block_id=0;
	player_one.type=cap;
	player_two.type=car;
	player_two.current_block_id=0;

	init_the_board(board);
	show_board(board,player_one, player_two);
	//buy_property(&board[4],&player_one);
	//sell_property(board, &player_one );
	gameplay (board,player_one ,player_two );


	return 0;
}

void init_the_board(block board[20])
{
	board[0].block_id=0;
	board[0].name="Start";
	board[0].price=0;
	board[0].rent=0;
	board[0].rent_1=0;
	board[0].rent_2=0;
	board[0].rent_3=0;
	board[0].house_price=0;
	board[0].house_count=0;
	board[0].type=start;
	board[0].owner.type=noone;

	board[1].block_id=1;
	board[1].name="Esenyurt";
	board[1].price=16000;
	board[1].rent=800;
	board[1].rent_1=4000;
	board[1].rent_2=9000;
	board[1].rent_3=25000;
	board[1].house_price=10000;
	board[1].type=property;
	board[1].owner.type=noone;		//in this play there are two person 1 is cap other one is car so at the beginnigng of the game no one block belongs a player
	board[1].house_count=0;



	board[2].block_id=2;
	board[2].name="Car Park";
	board[2].price=0;
	board[2].rent=1500;
	board[2].rent_1=0;
	board[2].rent_2=0;
	board[2].rent_3=0;
	board[2].house_price=0;
	board[2].type=tax;
	board[2].owner.type=noone;
	board[2].house_count=0;


	board[3].block_id=3;
	board[3].name="Tuzla";
	board[3].price=16500;
	board[3].rent=850;
	board[3].rent_1=4250;
	board[3].rent_2=9500;
	board[3].rent_3=26000;
	board[3].house_price=12000;
	board[3].type=property;
	board[3].owner.type=noone;
	board[3].house_count=0;


	board[4].block_id=4;
	board[4].name="Arnavutkoy";
	board[4].price=17000;
	board[4].rent=875;
	board[4].rent_1=4500;
	board[4].rent_2=10000;
	board[4].rent_3=28000;
	board[4].house_price=12000;
	board[4].type=property;
	board[4].owner.type=noone;
	board[4].house_count=0;

	board[5].block_id=5;
	board[5].name="Wait 2 Turn";
	board[5].price=0;
	board[5].rent=2;
	board[5].rent_1=0;
	board[5].rent_2=0;
	board[5].rent_3=0;
	board[5].house_price=0;
	board[5].type=punish;
	board[5].owner.type=noone;


	board[6].block_id=6;
	board[6].name="Catalca";
	board[6].price=20000;
	board[6].rent=1000;
	board[6].rent_1=5000;
	board[6].rent_2=12000;
	board[6].rent_3=30000;
	board[6].house_price=13000;
	board[6].type=property;
	board[6].owner.type=noone;
	board[6].house_count=0;

	board[7].block_id=7;
	board[7].name="Beykoz";
	board[7].price=23000;
	board[7].rent=1100;
	board[7].rent_1=5500;
	board[7].rent_2=12500;
	board[7].rent_3=33000;
	board[7].house_price=13000;
	board[7].type=property;
	board[7].owner.type=noone;
	board[7].house_count=0;

	board[8].block_id=8;
	board[8].name="Car Fix";
	board[8].price=0;
	board[8].rent=1750;
	board[8].rent_1=0;
	board[8].rent_2=0;
	board[8].rent_3=0;
	board[8].house_price=0;
	board[8].type=tax;
	board[8].owner.type=noone;
	board[8].house_count=0;

	board[9].block_id=9;
	board[9].name="Maltepe";
	board[9].price=30000;
	board[9].rent=1350;
	board[9].rent_1=7000;
	board[9].rent_2=15000;
	board[9].rent_3=40000;
	board[9].house_price=15000;
	board[9].type=property;
	board[9].owner.type=noone;
	board[9].house_count=0;

	board[10].block_id=10;
	board[10].name="Bills";
	board[10].price=0;
	board[10].rent=2000;
	board[10].rent_1=0;
	board[10].rent_2=0;
	board[10].rent_3=0;
	board[10].house_price=0;
	board[10].type=tax;
	board[10].owner.type=noone;

	board[11].block_id=11;
	board[11].name="Sisli";
	board[11].price=33000;
	board[11].rent=1500;
	board[11].rent_1=8000;
	board[11].rent_2=16000;
	board[11].rent_3=42000;
	board[11].house_price=16000;
	board[11].type=property;
	board[11].owner.type=noone;
	board[11].house_count=0;

	board[12].block_id=12;
	board[12].name="Oil";
	board[12].price=0;
	board[12].rent=2250;
	board[12].rent_1=0;
	board[12].rent_2=0;
	board[12].rent_3=0;
	board[12].house_price=0;
	board[12].type=tax;
	board[12].owner.type=noone;
	board[12].house_count=0;

	board[13].block_id=13;
	board[13].name="Atasehir";
	board[13].price=35000;
	board[13].rent=1600;
	board[13].rent_1=8500;
	board[13].rent_2=17000;
	board[13].rent_3=45000;
	board[13].house_price=17000;
	board[13].type=property;
	board[13].owner.type=noone;
	board[13].house_count=0;

	board[14].block_id=14;
	board[14].name="Sariyer";
	board[14].price=40000;
	board[14].rent=1750;
	board[14].rent_1=9500;
	board[14].rent_2=19000;
	board[14].rent_3=48000;
	board[14].house_price=19000;
	board[14].type=property;
	board[14].owner.type=noone;
	board[14].house_count=0;

	board[15].block_id=15;
	board[15].name="Wait 1 Turn";
	board[15].price=0;
	board[15].rent=1;
	board[15].rent_1=0;
	board[15].rent_2=0;
	board[15].rent_3=0;
	board[15].house_price=0;
	board[15].type=punish;
	board[15].owner.type=noone;

	board[16].block_id=16;
	board[16].name="Kadikoy";
	board[16].price=43000;
	board[16].rent=1900;
	board[16].rent_1=11000;
	board[16].rent_2=21500;
	board[16].rent_3=55000;
	board[16].house_price=23000;
	board[16].type=property;
	board[16].owner.type=noone;
	board[16].house_count=0;

	board[17].block_id=17;
	board[17].name="Besiktas";
	board[17].price=60000;
	board[17].rent=2500;
	board[17].rent_1=15000;
	board[17].rent_2=28000;
	board[17].rent_3=60000;
	board[17].house_price=30000;
	board[17].type=property;
	board[17].owner.type=noone;
	board[17].house_count=0;

	board[18].block_id=18;
	board[18].name="Vocation";
	board[18].price=0;
	board[18].rent=5000;
	board[18].rent_1=0;
	board[18].rent_2=0;
	board[18].rent_3=0;
	board[18].house_price=0;
	board[18].type=tax;
	board[18].owner.type=noone;

	board[19].block_id=19;
	board[19].name="Bebek";
	board[19].price=70000;
	board[19].rent=3500;
	board[19].rent_1=20000;
	board[19].rent_2=35500;
	board[19].rent_3=65000;
	board[19].house_price=35000;
	board[19].type=property;
	board[19].owner.type=noone;
	board[19].house_count=0;

}
// in this part i separated the code 3 part
void show_board(block board[20],player player_one, player player_two)
{
	int i,j,k=19;
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("|");

	for (i = 0; i < 16; ++i)
	{	
		if (i<6)			//first part
		{
			printf("%12s	|",board[i].name );

			if (i==5)
			{
				printf("\n|");

				for (j = 0; j < 6; ++j)
				{	
					if (board[j].price!=0)
						printf("	%d$	|",board[j].price);
					else if(board[j].type==tax)
						printf("	%d$	|",board[j].rent);
					else
						printf("		|" );

					if (j==5)
					{
						/* car sekillerin gosterimi */
						printf("\n|");
						for (j = 0; j < 6; ++j)
						{	
							if (player_one.current_block_id==player_two.current_block_id && player_one.current_block_id==j)
							{
								printf("2's here	|");
							}
							else if (player_one.current_block_id==j)
								printf("%9s	|",player_one.name );
							else if (player_two.current_block_id==j)
								printf("%9s	|",player_two.name );
							else
								printf("		|" );

						}
					}
				}
			}
		}

		else if (i<10)	//second part i used two variable i and k
		{
			if (i==6)
				printf("\n-------------------------------------------------------------------------------------------------\n");

			printf("|");
			printf("%12s	|",board[k].name );
			printf("								|%12s	|\n",board[i].name );
			

			if (board[k].price!=0)
				printf("|	%d$	|",board[k].price);
			else if(board[k].type==tax)
				printf("	%d$	|",board[k].rent);
			else
				printf("|		|" );
				
			if (board[i].price!=0)
				printf("								|	%d$	|",board[i].price );
			else if(board[i].type==tax)
				printf("								|	%d$	|",board[i].rent);
			else
				printf("								|		|");

			printf("\n");

			if (player_one.current_block_id==player_two.current_block_id && player_one.current_block_id==k)
				{
					printf("|   2's here    |								");
				}

			else if (player_one.current_block_id==k)
				printf("|%9s	|								",player_one.name );

			else if (player_two.current_block_id==k)
			{
				printf("|%9s	|								",player_two.name );
			}
			else
				printf("|		|								");

			if (player_one.current_block_id==player_two.current_block_id && player_one.current_block_id==i)
			{
				printf("|    2's here	|\n");
			}

			else if (player_one.current_block_id==i)
				printf("|%9s	|								",player_one.name );

			else if (player_two.current_block_id==i)
			{
				printf("|%9s	|								",player_two.name );
			}
			else
				printf("|		|");

			if (i!=9)
				printf("\n-----------------								-----------------\n");

			else
				printf("\n-------------------------------------------------------------------------------------------------\n");
			
			k--;
		}

		else if (i>9)		//third part  
		{
			if (i==10)
				printf("|");

			printf("%12s	|",board[25-i].name );		//writing reversely
			
			if (i==15)
			{
				
				printf("\n|");

				for (j = 15; j > 9; --j)
				{	
					if (board[j].price!=0)
						printf("	%d$	|",board[j].price);
					else if(board[j].type==tax)
						printf("	%d$	|",board[j].rent);
					else
						printf("		|" );

					if (j==10)
					{
						/* car sekillerin gosterimi */
						printf("\n|");
						for (j = 15; j >9; --j)
						{	
							if (player_one.current_block_id==player_two.current_block_id && player_one.current_block_id==j)
							{
								printf("2's here	|");
							}
							else if (player_one.current_block_id==j)
								printf("%9s	|",player_one.name );
							else if (player_two.current_block_id==j)
								printf("%9s	|",player_two.name );
							else
								printf("		|" );
						}
					}
				}
			}	
		}
	}
	printf("\n-------------------------------------------------------------------------------------------------\n");
}

void show_properties(block board[20])
{
	int i,select;

	printf("\nPlease select a property to see details:\n");
	while(select!=0)
	{
		for (int i = 0; i < 19; ++i)
		{
			if (board[i].type==property)
			{
				printf("%d-	%s\n",i,board[i].name );
			}
		}
		printf("0-	Exit\n");
		scanf("%d",&select);

		if (select!=0)
		{
			printf("-----------------------------------------\n");
			printf("|		%8s		|",board[select].name);
			printf("\n-----------------------------------------\n");
			printf("|	Rent 		%d$		|\n",board[select].rent);
			printf("|	Rent 1 H	%d$		|\n",board[select].rent_1);
			printf("|	Rent 2 H	%d$		|\n",board[select].rent_2);
			printf("|	Rent 3 H	%d$		|\n",board[select].rent_3);
			printf("-----------------------------------------\n");
			printf("|	House Price	%d$		|\n",board[select].house_price);
			printf("-----------------------------------------\n");
			printf("\n");
		}
	}
}
void buy_property( block* current_block, player* current_player)
{
	int count,most_house,flag=0,cost;
	char buy;
	// i used current_block->owner.type==noone as the define who is the owner of the property
	if (current_player->current_block_id==current_block->block_id && current_block->type==property && current_block->price<=current_player->account && current_block->owner.type==noone)
	{
		printf("Do you want to buy this property ? (Yes=y,No=n)\n");
		scanf(" %c",&buy);
		if (buy=='y' || buy=='Y')
		{
			current_player->account=current_player->account - current_block->price;
			current_block->owner.type=current_player->type;							//now player buyed the property
			printf("Do you want to build house?(Yes=y,No=n)\n");
			scanf(" %c",&buy);

			if (buy=='y' || buy=='Y')
			{
				if (current_player->account>=current_block->house_price)
				{
					while(flag!=1)
					{					
						most_house=current_player->account/current_block->house_price;
						if (most_house>3)
						{
							most_house=3;
						}
						printf("Your current money %d \na house cost is %d\nYou can build at most %d\n\nHow many house do you want to build ? ",current_player->account,current_block->house_price,most_house );
						scanf("%d",&count);
						if (count<1 || count>most_house)	//input controlled (input musnt be negative and more than money cost and doesnt more than 3)
						{
							printf("Wrong input please try again!!\n");
						}
						else
						{
							cost=current_block->house_price*count;
							current_player->account=current_player->account-cost;
							current_block->house_count=count;
							flag=1;
							printf("Process completed %d, house built\n",count );
						}
					}
				}
				else
					printf("Unfortunatelly you have not enough money to building house but ");
			}
			printf("Process completed, property bought\n");			
		}
	}
	else
		printf("You cant buy this block\n");
}
void sell_property(block board[20], player* current_player)
{
	int i,count,select=1,house, flag=1;
	while(select!=0)
	{
		count=0;
		printf("\nYou have :");
		for (i = 0; i <20 ; ++i)
		{
			if (board[i].owner.type==current_player->type)
			{
				printf("\n%d- %s",i,board[i].name);
				count++;
			}
		}
		if (count==0)
		{
			printf(" not any property!\n");
			select=0;
		}
		else
		{
			printf("\n0- Exit\nWhich one do you want to sell?\n");
			scanf("%d",&select);

			if (select!=0 && board[select].owner.type==current_player->type)
			{
				board[select].owner.type=noone;			//now owner changed no one (noone)is owner this property.
				printf("select.type=%d\n",board[select].owner.type );
				board[select].house_count=0;
				printf("Property sold!\nYour old account= %d $\n",current_player->account );
				current_player->account+=board[select].price/2+(board[select].house_price*board[select].house_count)/2;
				printf("Your new account= %d $\n",current_player->account );
			}
		}		
	}
}
void gameplay (block board[20], player player_one, player player_two)
{
	int select,turn=1,dice=0,crrent_block,number_of_house,flag=0,tax1,count_p=0,i;
	while(flag!=1)
	{	
		if (turn%2==1)
		{
			printf("Player 1.st Turn (cap)\n");
		}
		else
			printf("Player 2.nd Turn (car)\n");

		printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy Property\n6 - Buy house\n7 - Sell property\n8 - Show all proporties\n0 - End turn\nPlease select an option to continue:\n");
		scanf("%d",&select);
		

		switch(select)
		{
			case 1:
				
				if (dice==0 && turn%2==1)				//this is for define who's turn and dice for controlled only 1 roll dice
				{
					dice=rand()%6+1;
					printf("Dice= %d\n",dice);
					player_one.current_block_id+=dice;
					if (player_one.current_block_id>19)			//if player one take the tour he gains money and current id should define again
					{
						player_one.current_block_id-=20;
						player_one.account+=15000;			
					}
					show_board(board,player_one, player_two);
					if (board[player_one.current_block_id].type==property && board[player_one.current_block_id].owner.type==car )	//payment the other players to rent
					{	
						if (board[player_one.current_block_id].house_count==0)
							tax1=board[player_one.current_block_id].rent;
						else if (board[player_one.current_block_id].house_count==1)
							tax1=board[player_one.current_block_id].rent_1;
						else if (board[player_one.current_block_id].house_count==2)
							tax1=board[player_one.current_block_id].rent_2;
						else if (board[player_one.current_block_id].house_count==3)
							tax1=board[player_one.current_block_id].rent_3;

						player_one.account-=tax1;
						player_two.account+=tax1;
						printf("You paid rent the other player %d$\nNew account= %d$\n",tax1,player_one.account);
					}

					if (board[player_one.current_block_id].type==tax)
					{
						tax1=board[player_one.current_block_id].rent;
						player_one.account-=tax1;
						printf("You paid tax: %d$\nNew account= %d$\n:",tax1,player_one.account);
					}
					if (board[player_one.current_block_id].type==punish && player_one.turn_to_wait==0)		// punish
					{
						player_one.turn_to_wait=board[player_one.current_block_id].rent;
					}
					if (player_one.account<=0)
					{
						printf("You will bankrupt if you dont sell any property so you have to sell property\n");
						sell_property(board, &player_one );
					}
				}
				else if(dice==0 && turn%2==0)
				{
					dice=rand()%6+1;
					printf("Dice= %d\n",dice);

					player_two.current_block_id+=dice;
					if (player_two.current_block_id>19)			
					{
						player_two.current_block_id-=20;
						player_two.account+=15000;			
					}
					show_board(board,player_one, player_two);

					if (board[player_two.current_block_id].type==property && board[player_two.current_block_id].owner.type==cap )	//its about payment of rent
					{	
						if (board[player_two.current_block_id].house_count==0)
							tax1=board[player_two.current_block_id].rent;
						else if (board[player_two.current_block_id].house_count==1)
							tax1=board[player_two.current_block_id].rent_1;
						else if (board[player_two.current_block_id].house_count==2)
							tax1=board[player_two.current_block_id].rent_2;
						else if (board[player_two.current_block_id].house_count==3)
							tax1=board[player_two.current_block_id].rent_3;

						player_two.account-=tax1;
						player_one.account+=tax1;
						printf("You paid rent the other player %d$\nNew account= %d$",tax1,player_two.account );
					}
					if (board[player_two.current_block_id].type==tax)
						{
						tax1=board[player_two.current_block_id].rent;
						player_two.account-=tax1;
						printf("You paid tax: %d$\nNew account= %d$\n:",tax1,player_two.account);
						}

					if (board[player_two.current_block_id].type==punish && player_two.turn_to_wait==0)
					{
						player_two.turn_to_wait=board[player_two.current_block_id].rent+1;
					}

					if (player_two.account<=0)
					{
						printf("You will bankrupt if you dont sell any property so you have to sell property\n");
						sell_property(board, &player_two );
					}	
				}
				else
					printf("You can roll dice only once every turn!\n");

				break;

			case 2:
				if (turn%2==1)
				{
					printf("Your account= %d$\n",player_one.account );
				}
				else
				{
					printf("Your account= %d$\n",player_two.account );
				}
				break;

			case 3:
				if (turn%2==1)
				{
					printf("\nYou have :");
					for (i = 0; i <20 ; ++i)
					{
						if (board[i].owner.type==player_one.type)
						{
							printf("\n%d- %s\n",i,board[i].name);
							count_p++;
						}
					}
					if (count_p==0)
					{
						printf(" not any property!\n");
					}
					count_p=0;
				}
				else
				{
					printf("\nYou have :");
					for (i = 0; i <20 ; ++i)
					{
						if (board[i].owner.type==player_two.type)
						{
							printf("\n%d- %s",i,board[i].name);
							count_p++;
						}
					}
					if (count_p==0)
					{
						printf(" not any property!\n");
					}
					count_p=0;
				}
				break;

			case 4:
				
				if (turn%2==1)
				{
					crrent_block= player_one.current_block_id;
				}
				else
				{
					crrent_block= player_two.current_block_id;
				}

				printf("-----------------------------------------\n");
				printf("|		%8s		|",board[crrent_block].name);
				printf("\n-----------------------------------------\n");

				if (board[crrent_block].type==property)
				{
				printf("|	Rent 		%d$		|\n",board[crrent_block].rent);
				printf("|	Rent 1 H	%d$		|\n",board[crrent_block].rent_1);
				printf("|	Rent 2 H	%d$		|\n",board[crrent_block].rent_2);
				printf("|	Rent 3 H	%d$		|\n",board[crrent_block].rent_3);
				printf("-----------------------------------------\n");
				printf("|	House Price	%d$		|\n",board[crrent_block].price);
				printf("-----------------------------------------\n");
				printf("|	Built number of House	%d	|\n",board[crrent_block].house_count);
				printf("\n");
				if (board[crrent_block].owner.type==car)
					printf("Owner of the this property is cap (player_one)\n");

				else if(board[crrent_block].owner.type==cap)
					printf("Owner of the this property is car (player_two)\n");

				else
					printf("Owner of the this property is no_one\n");
				}

				case 5:
				if (turn%2==1)
				{
					buy_property(&board[player_one.current_block_id],&player_one);
					printf("Your account= %d$\n\n",player_one.account );
					
				}
				else
				{
					buy_property(&board[player_two.current_block_id],&player_two);
					printf("Your account= %d$\n\n",player_two.account );
				}
				break;

				case 6:// if player want to buy firstly he must on the block , and there are less than three house and it must be property and have enough money and this block must belong to player
				
					if (turn%2==1)
					{
						if(player_one.account>board[player_one.current_block_id].house_price && board[player_one.current_block_id].house_count<3 && board[player_one.current_block_id].type==property && board[player_one.current_block_id].type==property && board[player_one.current_block_id].owner.type==player_one.type)
						{
							player_one.account-=board[player_one.current_block_id].house_price;
							board[player_one.current_block_id].house_count++;
							printf("Process completed you bought 1 house you have %d house here block\n",board[player_one.current_block_id].house_count );

						}
						else
							printf("You cant build house this block.\n");
					}
					else
					{
						if(player_two.account>board[player_two.current_block_id].house_price && board[player_two.current_block_id].house_count<3 && board[player_two.current_block_id].type==property && board[player_two.current_block_id].type==property && board[player_two.current_block_id].owner.type==player_two.type)
						{
							player_two.account-=board[player_two.current_block_id].house_price;
							board[player_two.current_block_id].house_count++;
							printf("Process completed you bought 1 house you have %d house here block\n",board[player_two.current_block_id].house_count );

						}
						else
							printf("You cant build house this block.\n");
					}
			
				break;

				case 7:
				if (turn%2==1)
				{
					sell_property(board, &player_one );
				}
				else
				{
					sell_property(board, &player_two);
				}
				break;

				case 8:
					
					show_properties(board);
				break;

				case 0:
				if (dice!=0)	//if dice == 0 player didnt move
				{
					if (turn%2==1)
					{
						if (player_one.turn_to_wait>0)
						{
						player_one.turn_to_wait--;
						turn=2;						//the other player's turn
						dice=0;
						}

						else
						{
							dice=0;
							turn++;		//other player's turn
						}
					}


					else if (turn%2==0)
					{
						if (player_two.turn_to_wait>0)
						{
						player_one.turn_to_wait--;
						turn=1;						//the other player's turn
						dice=0;
						}

						else
						{
							dice=0;
							turn++;		//other player's turn
						}
					}

					if (player_one.account<=0 )
					{
						flag=1;				//game finished player one bankrupt
						printf("Player one (cap) bankrupt, player two win!\n");
					}

					else if (player_two.account<=0)
					{
						flag=1;
						printf("Player one (car) bankrupt, player one win!\n");
					}
					
				}
				else
					printf("You should move end of turn\n");

				break;
			}
	}
}