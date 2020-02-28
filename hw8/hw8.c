#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define PROPERTY_COUNT 13
typedef enum block_type{start=0,property,fortune,tax,punish}b_type; //fortune block_type added
typedef enum player_type{none=-1,car,cap}player_type;

typedef struct          //defined a struct for fortune cards
{
    int card_no;
    char *explanation;
    int money;
    b_type type;
    
}fortune_card;

typedef struct
{
	player_type type;
	int current_block_id;
	int owned_blocks[PROPERTY_COUNT];
	int account;
	int turn_to_wait;
	char *player_name;
} player;

typedef struct bloc
{
    int id;
    char * name;
    int price;
    int rent;
    int rent_1;
    int rent_2;
    int rent_3;
    int house_price;
    int h_count;
    player owner;
    b_type type;
    fortune_card fortune;       //fortune card added block structure
    struct bloc *next;
} block;

int roll_dice()
{

    int i=rand()%6+1;
    return i;
}

block * find_the_id_in_linked(block *iter,int int_id)
{
	while(iter!=NULL)
	{

		if (iter->id==int_id)
		{
			return iter;
		}

		iter=iter->next;
	}

	printf("Wrong input your input interval must be 1-23\n");

	return iter;

}

void show_property_deed(block *root)
{
    block *iter;
    iter=root;
    int exit_flag=0,i,selection;
    while (exit_flag==0)
    {
        printf("Please select a property to see details:\n");
        while (iter!=NULL) 
            {            
                if (iter->type==property)
                    printf("%d -\t%s \n",iter->id,iter->name);
                iter=iter->next;
            }
        iter=root;    

        printf("0 -\tExit\n");
        scanf("%d",&selection);
        if (selection==0)
            exit_flag=1;
        else {

            iter=find_the_id_in_linked(iter,selection);
            if (selection > 0 && selection < 24 && iter->type == property) {
                printf("\n\n---------------------------------\n");
                if (strlen(iter->name) < 8)
                    printf("|\t\t%s\t\t|\n", iter->name);
                else
                    printf("|\t    %s\t\t|\n", iter->name);
                printf("---------------------------------\n");
                printf("|\tRent \t\t%d$\t|\n", iter->rent);
                printf("|\tRent 1 H \t%d$\t|\n", iter->rent_1);
                printf("|\tRent 2 H \t%d$\t|\n", iter->rent_2);
                printf("|\tRent 3 H \t%d$\t|\n", iter->rent_3);
                printf("---------------------------------\n");
                printf("|\tHouse Price \t%d$\t|\n", iter->house_price);
                printf("|\tHouse count \t%d\t|\n", iter->h_count);               
                printf("---------------------------------\n");
                if (iter->owner.type==-1)
                {
                    printf("   Owner of this property NOBODY \n\n\n");
                }
                else if (iter->owner.type==0)
                {
                    printf("   Owner of this property car\n\n\n");
                }
                else
                printf("   Owner of this property cap\n\n\n");

            }
            else printf("\nWrong Selection! Please Try Again.\n\n");
            
            iter=root;
        }

    }
}

void show_board(block *root, player player_one, player player_two)
{
	block *iter;
	block *iter2;
	iter=root;
	iter2=root;
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	int i=0,space_flag=0;
	for (i=0;i<7;i++)
	{
		iter=find_the_id_in_linked(iter,i);

        if (strlen(iter->name)<8)
		    printf("|\t%s\t\t",iter->name);
        else
            printf("|\t%s\t",iter->name);

        iter=root;
	}
	
	printf("|\n");
	for (i=0;i<7;i++)
	{
		iter=find_the_id_in_linked(iter,i);

		if (iter->type==property || iter->type==tax)
		    printf("|\t%d$ \t\t",iter->price);
		else if (strlen(iter->name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");

        iter=root;

	}
    printf("|\n");

    
    for (i=0;i<7;i++)
    {

    	iter=find_the_id_in_linked(iter,i);
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(iter->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }

        iter=root;

    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    //Middle
    for (i=0;i<5;i++)
    {
        //Names

    	iter=find_the_id_in_linked(iter,23-i);

        if (strlen(iter->name)<8)
            printf("|\t%s\t\t|",iter->name);
        else
            printf("|\t%s\t|",iter->name);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        iter2=find_the_id_in_linked(iter2,i+7);


        if (strlen(iter->name)<8)
            printf("|\t%s\t\t|",iter2->name);
        else if (iter->type==fortune)
        {
        	printf("|\t%s\t|",iter2->name);
        }
        else
            printf("|\t%s\t\t|",iter2->name);
        printf("\n");
        //prices


        if (iter->type==property || iter->type==tax)
            printf("|\t%d$ \t\t|",iter->price);
        else if (strlen(iter->name)<8)
            printf("|\t     \t|");
        else
            printf("|\t\t\t|");


        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        if (iter2->type==property || iter2->type==tax)
            printf("|\t%d$ \t\t",iter2->price);
        else if (strlen(iter2->name)<8)
            printf("|\t     \t");
        else
            printf("|\t\t \t");

        printf("|\n");
        //spaces

        space_flag=0;
        printf("|\t");
        if (23-i==player_one.current_block_id && 23-i==player_two.current_block_id)
        {
            printf("%s, %s \t|",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (23 - i == player_one.current_block_id) {
                printf("%s \t\t|", player_one.player_name);
                space_flag = 1;
            }
            if (23 - i == player_two.current_block_id) {
                printf("%s \t\t|", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(iter->name)<8)
                printf("\t\t|");
            else
                printf("    \t\t|");
        }

        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        space_flag=0;
        printf("|\t");
        if (7+i==player_one.current_block_id && 7+i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {

            if (7+i==player_one.current_block_id)
            {
                printf("%s \t\t",player_one.player_name);
                space_flag=1;
            }
            if (7+i==player_two.current_block_id)
            {
                printf("%s \t\t",player_two.player_name);
                space_flag=1;
            }
        }

        if (space_flag==0) {
            if (strlen(iter2->name)<8)
                printf("\t\t");
            else
                printf("    \t\t");
        }

        printf("|\n");
        if (i!=4) {
            printf("-------------------------");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            printf("-------------------------");
            printf("\n");
        }

        iter=root;
        iter2=root;

    }

    //bottom row
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=18;i>=12;i--)
    {
    	iter=find_the_id_in_linked(iter,i);
        if (strlen(iter->name)<8)
            printf("|\t%s\t\t",iter->name);
        else
            printf("|\t%s\t",iter->name);
        
        iter=root;
    }
    printf("|\n");
    for (i=18;i>=12;i--)
    {
    	iter=find_the_id_in_linked(iter,i);
        if (iter->type==property || iter->type==tax)
            printf("|\t%d$ \t\t",iter->price);
        else if (strlen(iter->name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
        iter=root;
    }
    printf("|\n");
    for (i=18;i>=12;i--)
    {
    	iter=find_the_id_in_linked(iter,i);

        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s, %s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(iter->name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }

        iter=root;

    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void init_board(block *iter)
{
    

    block temp;
	player temp_player;
	temp_player.type=none;

    fortune_card tempf;

    temp.id=0;
    temp.name="Start";
    temp.price=0;
    temp.rent=0;
    temp.rent_1=0;
    temp.rent_2=0;
    temp.rent_3=0;
    temp.owner=temp_player;
    temp.house_price=0;
    temp.h_count=0;
    temp.type=start;

    *iter=temp; 

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    temp.type=tax;
    *iter=temp;
    iter->name="Car park";
    iter->id=2;
    iter->price=1500;
    
    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->name="Car fix";
    iter->id=10;
    iter->price=1750;
    //board[temp.id]=temp;
    
	iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->name="Bills";
    iter->id=12;
    iter->price=2000;
   // board[temp.id]=temp;
    
    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->name="Oil";
    iter->id=14;
    iter->price=2250;
    //board[temp.id]=temp;
	
	iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->name="Vocation";
    iter->id=22;
    iter->price=5000;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    temp.type=punish;
    *iter=temp;
	iter->name="Wait 2 turn";
	iter->price=2;
    iter->id=6;
    //board[temp.id]=temp;
	
	iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->name="Wait 1 turn";
	iter->price=1;
    iter->id=18;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    temp.type=property;
    
    *iter=temp;
    iter->id=1;
    iter->name="Esenyurt";
    iter->price=16000;
    iter->rent=800;
    iter->rent_1=4000;
    iter->rent_2=9000;
    iter->rent_3=25000;
    iter->house_price=10000;
    iter->h_count=0;
   // board[temp.id]=temp;

	iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;
    
    *iter=temp;
    iter->id=4;
    iter->name="Tuzla";
    iter->price=16500;
    iter->rent=850;
    iter->rent_1=4250;
    iter->rent_2=9500;
    iter->rent_3=26000;
    iter->house_price=12000;
    iter->h_count=0;
   //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->id=5;
    iter->name="Arnavutkoy";
    iter->price=17000;
    iter->rent=850;
    iter->rent_1=4500;
    iter->rent_2=10000;
    iter->rent_3=28000;
    iter->house_price=12000;
    iter->h_count=0;
   // board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->id=7;
    iter->name="Catalca";
    iter->price=20000;
    iter->rent=1000;
    iter->rent_1=5000;
    iter->rent_2=12000;
    iter->rent_3=30000;
    iter->house_price=13000;
    iter->h_count=0;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
	iter->id=8;
    iter->name="Beykoz";
    iter->price=23000;
    iter->rent=1100;
    iter->rent_1=5500;
    iter->rent_2=12500;
    iter->rent_3=33000;
    iter->house_price=13000;
    iter->h_count=0;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
	iter->id=11;
    iter->name="Maltepe";
    iter->price=30000;
    iter->rent=1350;
    iter->rent_1=7000;
    iter->rent_2=15000;
    iter->rent_3=40000;
    iter->house_price=15000;
    iter->h_count=0;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
	iter->id=13;
    iter->name="Sisli";
    iter->price=33000;
    iter->rent=1500;
    iter->rent_1=8000;
    iter->rent_2=16000;
    iter->rent_3=42000;
    iter->house_price=16000;
    iter->h_count=0;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
	iter->id=16;
    iter->name="Atasehir";
    iter->price=35000;
    iter->rent=1600;
    iter->rent_1=8500;
    iter->rent_2=17000;
    iter->rent_3=45000;
    iter->house_price=17000;
    iter->h_count=0;
    //board[temp.id]=temp;
    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
	iter->id=17;
    iter->name="Sariyer";
    iter->price=40000;
    iter->rent=1750;
    iter->rent_1=9500;
    iter->rent_2=19000;
    iter->rent_3=48000;
    iter->house_price=19000;
    iter->h_count=0;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
	iter->id=19;
    iter->name="Kadikoy";
    iter->price=43000;
    iter->rent=1900;
    iter->rent_1=11000;
    iter->rent_2=21500;
    iter->rent_3=55000;
    iter->house_price=23000;
    iter->h_count=0;
   // board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
	iter->id=20;
    iter->name="Besiktas";
    iter->price=60000;
    iter->rent=2500;
    iter->rent_1=15000;
    iter->rent_2=28000;
    iter->rent_3=60000;
    iter->house_price=30000;
    iter->h_count=0;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
	iter->id=23;
    iter->name="Bebek";
    iter->price=70000;
    iter->rent=3500;
    iter->rent_1=20000;
    iter->rent_2=35500;
    iter->rent_3=65000;
    iter->house_price=35000;
    iter->h_count=0;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    temp.type=fortune;
    temp.name="Fortune Card";
    *iter=temp;
    iter->id=3;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->id=9;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->id=15;
    //board[temp.id]=temp;

    iter->next=(block*)malloc(sizeof(block));
    iter=iter->next;

    *iter=temp;
    iter->id=21;
    //board[temp.id]=temp;

    iter=iter->next;
    iter->next=NULL;
}

void show_player_properties(block *root, player player_h)
{
    block *iter;
    iter=root;
    int i,counter=0,selection;
    while (selection!=0) {
        printf("----------------------------------------\n");
        for (i = 0; i < PROPERTY_COUNT; i++) {
            if (player_h.owned_blocks[i] != -1) {
                iter=find_the_id_in_linked(iter,player_h.owned_blocks[i]);
                printf("%d - %s\n", iter->id,iter->name);
                counter++;
                iter=root;
            }

        }
        if (counter == 0)
        {
            printf("You have not owned any property yet.\n");
            printf("----------------------------------------\n");
            selection=0;
        }
        else
        {

            printf("0 - Back \n");
            printf("----------------------------------------\n");
            printf("Please select an property to see details.\n");
            scanf("%d", &selection);

            if (selection!=0) {
                iter=root;
                iter=find_the_id_in_linked(iter,selection);
                if (iter->owner.type != player_h.type)
                    printf("You made a wrong selection!\n");
                else {
                    printf("\n\n---------------------------------\n");
                    if (strlen(iter->name) < 8)
                        printf("|\t\t%s\t\t|\n", iter->name);
                    else
                        printf("|\t    %s\t\t|\n", iter->name);
                    printf("---------------------------------\n");
                    printf("|\tRent \t\t%d$\t|\n", iter->rent);
                    printf("|\tRent 1 H \t%d$\t|\n", iter->rent_1);
                    printf("|\tRent 2 H \t%d$\t|\n", iter->rent_2);
                    printf("|\tRent 3 H \t%d$\t|\n", iter->rent_3);
                    printf("---------------------------------\n");
                    printf("|\tHouse Price \t%d$\t|\n",iter->house_price);
                    printf("|\tHouse count \t%d\t|\n", iter->h_count);
                    printf("---------------------------------\n\n\n");
                }
            }
        }
            iter=root;
    }

}

int build_house(block* current_block, player* current_player)
{
    int flag=0;
    if (current_player->type==current_block->owner.type)
    {
        if (current_block->h_count<3)
        {
            if (current_block->house_price<=current_player->account)
            {
                flag=1;
                current_player->account-=current_block->house_price;
                current_block->h_count+=1;
            }
            else
                printf("You don't have enough money to build house!\n");
        }
        else
            printf("You can't buy more than 3 houses in a property!\n");
    }
    else
        printf("You don't have permission to build house on this property!\n ");
    return flag;
}

int count_properties(player current_player)
{
    int i,count=0;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        if (current_player.owned_blocks[i]!=-1)
            count++;
    }
    return count;
}

void sell_property(block *root, player* player_h)
{
    block *iter;
    iter=root;
    int property_id,flag=0,is_owned=-1,i,index,counter=0;
        if (count_properties(*player_h)!=0)
        {
            for (i = 0; i < PROPERTY_COUNT; i++) {
                if (player_h->owned_blocks[i] != -1) {

                    iter=find_the_id_in_linked(iter,player_h->owned_blocks[i]);
                    printf("%d - %s\n", iter->id,
                           iter->name);
                    counter++;
                    iter=root;
                }

            }
            printf("0 - Back\n");
            printf("Please select to sell the property:\n");

            scanf("%d",&property_id);
            if (property_id!=0)
            {
                for(i=0;i<PROPERTY_COUNT;i++)
                {
                    if (player_h->owned_blocks[i]==property_id)
                    {
                        is_owned=1;
                        index=i;
                        break;
                    }
                }
                if(is_owned!=-1)
                {
                    iter=find_the_id_in_linked(iter,property_id);
                    player_h->owned_blocks[index]=-1;
                    player temp;
                    iter->owner.type=none;
                    if(iter->h_count==0)player_h->account+=iter->price/2;
                    if(iter->h_count==1)
                    {
                        player_h->account+=(iter->price+iter->house_price)/2;
                    }
                    if(iter->h_count==2)
                    {
                        player_h->account+=(iter->price+(2*iter->house_price))/2;
                    }
                    if(iter->h_count==3)
                    {
                        player_h->account+=(iter->price+(3*iter->house_price))/2;
                    }
                }
            }
        } else
        {
            printf("You don't have any property to sell.\n");
        }

}
void sell_computer_property(block *root, player *computer)
{
    block *iter,*iter2;
    int max=0,i,index;
    iter=root;
    while(iter!=NULL)
    {
        if (iter->type==property && iter->price>max && iter->owner.type==cap)
        {
            iter2=iter;             //to find highest price
        }
        iter=iter->next;
    }

    for (i = 0; i <PROPERTY_COUNT ; ++i)
    {
        if (computer->owned_blocks[i]==iter2->id)
        {
            index=iter2->id;
        }
    }

    computer->owned_blocks[index]=-1;
    iter2->owner.type=none;
    if(iter2->h_count==0)
        computer->account+=iter2->price/2;
    if(iter2->h_count==1)
       computer->account+=(iter2->price+iter2->house_price)/2;
    if(iter2->h_count==2)
        computer->account+=(iter2->price+(2*iter2->house_price))/2;
    if(iter2->h_count==3)
        computer->account+=(iter2->price+(3*iter2->house_price))/2;

    iter2->h_count=0;

    printf("Computer sold %s !\n",iter2->name );
}
int insufficient_fund(block *root, player* player_h,int required_money)
{
    block *iter;
    iter=root;
    int selection,flag=1;
    while (selection!=0 && player_h->account<required_money && count_properties(*player_h)!=0)
    {

        printf("You don't have enough money to continue your transaction.You need %d$ more. Please select an option to continue: \n",required_money-player_h->account);
        printf("1- Sell Property\n");
        printf("2- Show my Properties\n");
        printf("3- Show my Account\n");
        printf("0- Back\n");
        scanf("%d",&selection);
        switch (selection)
        {
            case 1:
                sell_property(iter,player_h);
                iter=root;
                break;
            case 2:
                show_player_properties(iter,*player_h);
                iter=root;
                break;
            case 3:
                printf("\n\nThere are %d $ in your account.\n\n",player_h->account);
                break;
            case 0:
                flag=0;
                break;
            default:
                printf("You made a wrong selection!\n");
                break;

        }
    }
    return flag;

}

void pay_rent(block *root, player* current_player,player * owner)
{
    int rent=0,owned_property_count;
    block * iter, *iter2;
    iter2=root;
    iter=root;
    iter=find_the_id_in_linked(iter,current_player->current_block_id);
    rent=iter->rent;
    if (iter->h_count==1)rent=iter->rent_1;
    if (iter->h_count==2)rent=iter->rent_2;
    if (iter->h_count==3)rent=iter->rent_3;
    if (rent>current_player->account && current_player->type==car)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            insufficient_fund(iter2,current_player,rent);
            iter2=root;
            owned_property_count=count_properties(*current_player);
        }
    }
    else if (rent>current_player->account && current_player->type==cap)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            sell_computer_property(iter2,current_player);
            iter2=root;
            owned_property_count=count_properties(*current_player);
        }
    }
    if (rent<current_player->account)
    {
        current_player->account-=rent;
        owner->account+=rent;
        if (current_player->type==car)
        {
            printf("You paid %d$ to cap\n",rent);
        }
        else
            printf("Cap paid %d$ to you\n",rent);
    } else
        current_player->account=0;
}

void add_to_owned(player* current_player)
{
    for (int i = 0; i < PROPERTY_COUNT; ++i) {
        if (current_player->owned_blocks[i]==-1) {
            current_player->owned_blocks[i] = current_player->current_block_id;
            break;
        } else
            printf("%d ",current_player->owned_blocks[i]);
    }
    printf("\n");
}

void copy_owner(player* old, player* new)
{
    old->type=new->type;
    old->account=new->account;
    old->turn_to_wait=new->turn_to_wait;
    old->player_name=new->player_name;
    old->current_block_id=new->current_block_id;
    for (int i = 0; i < PROPERTY_COUNT; ++i) {
        old->owned_blocks[i]=new->owned_blocks[i];
    }
}

void buy_property(block* iter, player* player_h)
{
    if (iter->price<=player_h->account)
    {
        player_h->account-=iter->price;
        copy_owner(&iter->owner,player_h);
        add_to_owned(player_h);

        if (player_h->type==cap)
        {
            printf("Computer had bought %s.\n\n",iter->name);
            //printf("Computers account left %d$.\n",player_h->account);
        }
        else
        {
            printf("Congratiulations! You have buy %s.\n\n",iter->name);
            //printf("You left %d$ in your account.\n",player_h->account);
        }
        

    }
    else
        printf("You don't have enough money to buy this property!\n");
}

void house_dialog(block *root, player* current_player)
{
    block *iter;
    block *iter2;

    iter=root;
    iter2=root;
    iter=find_the_id_in_linked(iter,current_player->current_block_id);
    int house_flag=1,selection,insuf_flag=1,build_flag=1;
    while (house_flag && build_flag) {
        printf("Do you want to build house on %s ?\n",
               iter->name);
        printf("1- Yes\n");
        printf("2- No\n");
        scanf("%d", &selection);
        if (selection == 1) {

            if (current_player->account < iter->house_price) {
                while (count_properties(*current_player)!=0 && current_player->account<iter->house_price && insuf_flag==1)
                    insuf_flag=insufficient_fund(iter2,current_player,iter->house_price);
            }
            if (current_player->account >= iter->house_price)
                build_flag=build_house(iter, current_player);
            else
                house_flag=0;


        } else
            house_flag=0;
    }
}

void after_dice_menu(block *root, player* player_h, player* computer)
{
    block *iter,*iter2;
    iter2=root;
    iter=root;
    int selection,insuf_flag=1;
    iter=find_the_id_in_linked(iter,player_h->current_block_id);
    switch (iter->type)
    {
        case property:
            printf("%s has arrived %s \n",player_h->player_name,iter->name);
            if (iter->owner.type==none)
            {
                printf("Do you want to buy %s ?\n",iter->name);
                printf("1- Yes\n");
                printf("2- No\n");
                scanf("%d",&selection);
                if (selection==1)
                {

                    if (player_h->account<iter->price)
                    {
                        while (count_properties(*player_h)!=0 && player_h->account<iter->price && insuf_flag==1 )
                        {
                            insuf_flag=insufficient_fund(iter2,player_h,iter->price);
                        }
                        iter2=root;
                    }
                    buy_property(iter,player_h);
                    if (player_h->type==iter->owner.type)
                    {
                        iter2=root;
                        house_dialog(iter2,player_h);
                        iter2=root;

                    }

                }

            } else
            {
                pay_rent(iter2,player_h,computer);
                iter2=root;
            }
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",player_h->player_name,iter->name);
            while (count_properties(*player_h)!=0 && player_h->account<iter->price) {
                insuf_flag = insufficient_fund(iter2, player_h,iter->price);
                if (insuf_flag == 0 && player_h->account < iter->price)
                    printf("You must pay your tax!\n");
            }
            if (player_h->account>iter->price)
                player_h->account-=iter->price;
            else
            {
                player_h->account=0;
            }
            break;
        case punish:
            printf("%s has punished for %d turn. \n",player_h->player_name,iter->price);
            player_h->turn_to_wait+=iter->price;
            break;
        case fortune:
            iter2=root;
            fortune_f(iter2,player_h,computer );
            break;
    }
}
float avarage_properties_cost(block * root)
{
    int i=0,total=0;
    float avarage;
    while(root!=NULL)
    {
        if (root->type==property)
            total+=root->price;
        root=root->next;
    }
    avarage=total/(PROPERTY_COUNT-1);
    return avarage;
}
void computer_new_block(block *root, player * computer, player *player_h)
{
    block *iter,*iter2;
    int dice,total_properties=0, insuf_flag;
    iter2=root;
    iter=root;
    float avarage;
    iter=find_the_id_in_linked(iter,computer->current_block_id);

    printf("%s has arrived %s \n",computer->player_name,iter->name);

    switch (iter->type)
    {
        case property:

            if (iter->owner.type==none && computer->account>iter->price)
            {
                avarage=avarage_properties_cost(iter2);
                iter2=root;
                if (avarage>iter->price)
                    buy_property(iter,computer);
                //otherwise computer dice again and buy property according to dice
                else
                {
                    dice=roll_dice();
                    if (dice<4)
                    {
                        buy_property(iter,computer);
                    }
                } 
            }

            if (iter->owner.type==cap && iter->h_count<3 && computer->account>iter->house_price)   //if computer lands on a property it owns
            {
                while(iter2!=NULL)
                {
                    if (iter2->owner.type==cap)
                    {
                        total_properties++;
                    }
                    iter2=iter2->next;
                }
                iter2=root;
                if (total_properties>PROPERTY_COUNT/3.0)        //if computer owns 1/3 of all properties
                {
                    dice=roll_dice();
                    if (dice<4)
                    {
                        printf("Computer build an house on the %s\n",iter->name );
                        build_house(iter,computer);
                    }
                }
            }

            if (iter->owner.type==car)      //pay tax
            {
                pay_rent(iter2,computer,player_h);
                iter2=root;
            }
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",computer->player_name,iter->name);
            while (count_properties(*computer)!=0 && computer->account<iter->price) {
                iter2=root;
                sell_computer_property(iter2,computer);
            }
            if (computer->account>iter->price)
                computer->account-=iter->price;
            else
            {
                computer->account=0;
            }
            break;

        case punish:
            printf("%s has punished for %d turn. \n",computer->player_name,iter->price);
            computer->turn_to_wait+=iter->price;
            break;

        case fortune:
            fortune_f(iter2,computer,player_h);
            break;
    }   
}

void computer_turn(block *root, player *player_h, player * computer)
{
    block *iter,*iter2;
    iter=root;
    iter2=root;
    int dice;
    int next_block;

    //Dice rolling
    if (computer->turn_to_wait==0)
    {
        dice=roll_dice();
        printf("Computer rolled the dice: %d \n",dice);
        next_block=(computer->current_block_id + dice);
        if (next_block>=20)
            {
                computer->account+=10000;
                computer->current_block_id = next_block % 20;
            }
        else
           computer->current_block_id+=dice;                
        
        show_board(iter2,*computer,*player_h);
        iter2=root;
        computer_new_block(iter,computer,player_h);
    }
    else
    {
        printf("You need to wait %d turn to continue.\n",computer->turn_to_wait);
        computer->turn_to_wait-=1;
        //flag=0;
    }


}

void player_turn(block *root, player* player_h, player * computer)
{
    block *iter,*iter2;
    iter=root;
    iter2=root;
    int flag=1,next_block;
    while(flag)
    {
        int selection;
        printf("1 - Roll the dice\n");
        printf("2 - Show my account\n");
        printf("3 - Show my properties\n");
        printf("4 - Show property deeds\n");
        printf("5 - Buy Property\n");
        printf("6 - Buy house \n");
        printf("7 - Sell property\n");
        printf("Please select an option to continue (%s):\n",player_h->player_name);
        scanf("%d",&selection);
        switch(selection)
        {
            case 1:
                if (player_h->turn_to_wait==0) {
                    next_block=(player_h->current_block_id + roll_dice());
                    if (next_block>=20)player_h->account+=10000;
                    player_h->current_block_id = next_block % 20;
                    show_board(iter2,*computer,*player_h);
                    iter2=root;
                    after_dice_menu(iter,player_h,computer);
                    iter=root;
                    flag = 0;
                } else
                {
                    printf("You need to wait %d turn to continue.\n",player_h->turn_to_wait);
                    player_h->turn_to_wait-=1;
                    flag=0;
                }
                break;
            case 2:
                printf("\n\nThere are %d $ in your account.\n\n",player_h->account);
                break;
            case 3:
                show_player_properties(iter2,*player_h);
                iter2=root;
                break;
            case 4:
                show_property_deed(iter2);
                iter2=root;
                break;
            case 5:
                iter=find_the_id_in_linked(iter,player_h->current_block_id);
                if (iter->type==property && iter->owner.type==-1)
                {
                    buy_property(iter,player_h);
                    iter=root;
                }
                
                else
                {
                    iter=root;
                    printf("You don't have permission to buy this block!\n");
                }

                break;
            case 6:
                iter=find_the_id_in_linked(iter,player_h->current_block_id);

                if (player_h->type==iter->owner.type) {
                    house_dialog(iter2,player_h);
                }else
                {
                    printf("You don't have permission to build house on this block!\n");
                }
                break;
            case 7:
                sell_property(iter2,player_h);
                break;
            default:
                printf("Wrong selection!\n");
        }
    }
}

int check_end(player current_player)
{
    int owned_property_count=count_properties(current_player);
    if (current_player.account<=0 && owned_property_count==0)return 1;
    else return 0;
}

void play_game(block *root, player* computer, player* player_h)
{   
    int x;
    block *iter, *iter2;
    iter=root;
    iter2=root;
    int is_end=0;
    printf("Welcom to Monopoly! %s will roll the dice first.\n",computer->player_name);
    while(is_end!=1)
    {
        iter=root;
        iter2=root;
        printf("%s :%d$ , %s:%d$\n",computer->player_name,computer->account,player_h->player_name,player_h->account);
        computer_turn(iter,player_h,computer);
        iter=root;
        is_end=check_end(*computer);

        if (is_end==0)
        {
            printf("%s :%d$ , %s:%d$\n",computer->player_name,computer->account,player_h->player_name,player_h->account);
            player_turn(iter,player_h,computer);
            is_end=check_end(*player_h);
            iter=root;
            iter2=root;
            if (is_end==1)
                printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_h->player_name,player_h->player_name);
        } else
            printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",computer->player_name,computer->player_name);

    }

}

void init_owned(player* current_player)
{
    int i;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        current_player->owned_blocks[i]=-1;
    }

}

void fortune_f(block *root, player *current_player, player *other)
{
    block *iter, *iter2;
    iter=root;
    iter2=root;
    int random, suitable_for_build=0, max_house_price=0,select,flag=0,insuf_flag,owned_property_count;


    fortune_card f_card[5];

    random=rand()%5;

    f_card[0].card_no=1;
    f_card[0].money=0;
    f_card[0].type=fortune;
    f_card[0].explanation="Build a house on one of your properties for free";

    f_card[1].card_no=2;
    f_card[1].money=0;
    f_card[1].type=fortune;
    f_card[1].explanation="Roll a dice. If result is [1-3], move forward by 2 blocks. Else, move backward by 2 blocks.";

    f_card[2].card_no=3;
    f_card[2].money=5000;
    f_card[2].type=fortune;
    f_card[2].explanation="Pay 5.000 to the bank.";

    f_card[3].card_no=4;
    f_card[3].money=10000;
    f_card[3].type=fortune;
    f_card[3].explanation="Give 10.000 to the opponent.";

    f_card[4].card_no=5;
    f_card[4].money=20000;
    f_card[4].type=fortune;
    f_card[4].explanation="Take 20.000 from the bank.";

    if (random==0)
    {
        printf("The fortune card is Free house: %s\n",f_card[0].explanation );
        if (current_player->type==cap)      //if fortune cart for computer building house for the most expensive block
        {
            iter=root;
            while(iter!=NULL)
            {
                if (iter->type==property &&  iter->owner.type==cap && iter->h_count<3 && max_house_price<iter->house_price)
                {
                    suitable_for_build++;
                    iter2=iter;
                }
                iter=iter->next;
            }

            if (suitable_for_build==0)
            {
                printf("NO suitable block for house building!\n");
            }
            else
            {
                iter2->h_count++;
                printf("house built on the %s thanks to fortune card",iter2->name );
            }
            iter=root;
        }

        else
        {
            while(iter!=NULL)
            {
                if (iter->type==property &&  iter->owner.type==car && iter->h_count<3)
                {
                    suitable_for_build++;
                }
                iter=iter->next;
            }

            if (suitable_for_build==0)
            {
                printf("NO suitable block for house building!\n");
            }
            else
            {
                while(flag!=1)
                {
                    iter=root;
                    printf("Suitable blocks:\n");
                    while(iter!=NULL)
                    {
                        if (iter->type==property &&  iter->owner.type==car && iter->h_count<3)
                        {
                            printf("%d->%s\n",iter->id,iter->name );
                        }
                        iter=iter->next;
                    }
                    printf("Pick one of them: ");
                    scanf("%d",&select);
                    iter=root;
                    iter=find_the_id_in_linked(iter,select);
                    if (iter->type==property &&  iter->owner.type==car && iter->h_count<3)
                    {
                        iter->h_count+=1;
                        printf("house built on the %s thanks to fortune card",iter->name );
                        flag=1;
                    }
                    else
                        printf("Wrong selection try again\n");
                }
            }   
        }
    }

    else if (random==1)
    {
        int result;
        printf("The fortune card is Time Travel: %s\n",f_card[1].explanation );
        result=roll_dice();
        printf("Dice: %d\n",result );
        if (result<4)
        {
            current_player->current_block_id+=2;
            iter2=root;
            if (current_player->type==cap)
            {
                computer_new_block(iter2,current_player,other);     //to new transaction in new block
            }
            else
            {
                after_dice_menu(iter2,current_player,other);
            }
        }
        else
        {
            iter2=root;
            current_player->current_block_id-=2;

            if (current_player->type==cap)
            {
                computer_new_block(iter2,current_player,other);     //to new transaction in new block
            }
            else
            {
                after_dice_menu(iter2,current_player,other);
            }
        }

    }

    else if (random==2)
    {
        printf("The fortune card is Garnishment: %s\n",f_card[2].explanation );
        if (current_player->account>5000)
        {
            current_player->account-=5000;
        }


        else
        {
            if (current_player->type==cap)
            {
                owned_property_count=count_properties(*current_player);
                while(5000>current_player->account && owned_property_count!=0)
                {
                    iter2=root;
                    sell_computer_property(iter2,current_player);
                    owned_property_count=count_properties(*current_player);
                }

                current_player->account-=5000;

            }
            else
            {
                while (count_properties(*current_player)!=0 && current_player->account<5000)
                {
                    iter2=root;
                    insuf_flag = insufficient_fund(iter2, current_player,10000);
                    if (insuf_flag == 0 && current_player->account < 10000)
                        printf("You must pay your tax!\n");
                }

                 current_player->account-=5000;

            }
        }
    }
    else if (random==3)
    {
        printf("The fortune card is Generosity: %s\n",f_card[3].explanation );
        
        if (current_player->account>10000)
        {
            current_player->account-=10000;
            other->account+=10000;
        }

        else
        {
            if (current_player->type==cap)
            {
                while(10000>current_player->account && owned_property_count!=0)
                {
                    iter2=root;
                    sell_computer_property(iter2,current_player);
                    owned_property_count=count_properties(*current_player);
                }

                current_player->account-=10000;
                other->account+=10000;

            }
            else
            {
                while (count_properties(*current_player)!=0 && current_player->account<10000)
                {
                    iter2=root;
                    insuf_flag = insufficient_fund(iter2, current_player,10000);
                    if (insuf_flag == 0 && current_player->account < 10000)
                        printf("You must pay your tax!\n");
                }

                current_player->account-=10000;
                other->account+=10000;

            }            
        }
    }
    else if (random==4)
    {
        printf("The fortune card is Treasure Hunter: %s\n",f_card[4].explanation );
        current_player->account+=20000;
    }

}
int main()
{
    block *root;
    block *iter;
    root=(block *)malloc(sizeof(block));
   // block board[24];
    iter=root;
    init_board(iter);

    //init_board(board);
    srand(time(NULL));
    player computer,player_h;

    computer.player_name="Cap";
	computer.type=cap;
	computer.current_block_id=0;
    computer.turn_to_wait=0;
	computer.account=20000;
    init_owned(&computer);

	player_h.player_name="Car";
	player_h.type=car;
	player_h.current_block_id=0;
    player_h.turn_to_wait=0;
	player_h.account=50000;
    init_owned(&player_h);

    show_board(iter,computer,player_h);
    iter=root;
    play_game(iter,&computer,&player_h);
    //play_game(board,&player_one,&player_two);

    return 0;
}