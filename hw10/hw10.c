#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define sizeof_array 20

typedef struct node{
	int data;
	struct node * next;
}stack;

typedef struct node1{
	int data;
	struct node1 * next;
}queue;


typedef struct node4{					//double linked list for special traverse function

	int data;
	struct node4 *next, *previous;

}double_lnkd_lst;


typedef struct node3{
	int data;
	struct node3 *right_child, *left_child;
}bst;

bst* insert(bst *, bst *);

void inorder(bst *root)
{
	if(root!=NULL) // checking if the root is not null
	{
		inorder(root->right_child);// visiting right child
		printf(" %d ", root->data); // printing data at root
		inorder(root->left_child); // visiting left child
	}
}

void special_traverse(stack * , queue * , bst *);
void search(stack *, queue *, bst *, int );
void swap_s(stack *, stack * );
void swap_q(queue *, queue * );
void fill_structures(stack ** , queue **, bst ** , int []);
void ordered_print(stack * stack_, queue * queue_, bst * bst_);
void search_b(bst *root, int ,int *, int *,int *);


int main()
{

	int i,data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17,8, 23, 4};
	bst * bst_, *node_b;
	queue * queue_;
	stack * stack_;
	fill_structures(&stack_, &queue_, &bst_, data);
	ordered_print(stack_,queue_,bst_);
	search(stack_, queue_, bst_, 5);
	special_traverse(stack_, queue_, bst_);
	return 0;
}

bst* insert(bst *root, bst *new_node)
{
    //searching for the place to insert
    if(root==NULL)
    {	
        return new_node;
    }
    else if(new_node->data>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, new_node);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child, new_node);
    //return new_node;

}
void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[sizeof_array])
{
	*stack_=NULL;
	*bst_=NULL;
	*queue_=NULL;
	stack *iter_s=*stack_;
	stack *node_s;
	queue *node_q, *tail;
	bst *node_b;
	clock_t begin, end;
	double stack_t,queue_t,bst_t;
	int i;

	begin = clock();
	while(i<sizeof_array)				//filling stack
	{
		node_s=(stack*)malloc(sizeof(stack));
		node_s->data=data[i];
		node_s->next=NULL;

		if (*stack_==NULL)
		{
			*stack_=node_s;
		}

		else
		{
			node_s->next=*stack_;
			*stack_=node_s;
		}
		i++;
	}
	end = clock();
	stack_t= (double)(end - begin) / CLOCKS_PER_SEC;

	i=0;

	begin = clock();	
	while(i<sizeof_array)				//filling queue
	{
		node_q=(queue*)malloc(sizeof(queue));
		node_q->data=data[i];
		node_q->next=NULL;

		if (*queue_==NULL)
		{
			*queue_=node_q;
			tail=node_q;
		}
		else
		{
			tail->next=node_q;
			tail=node_q;
		}
		i++;
	}
	end = clock();
	queue_t= (double)(end - begin) / CLOCKS_PER_SEC;
	
	i=0;

	begin = clock();	
	while(i<sizeof_array)				//filling tree
	{
		node_b=(bst*)malloc(sizeof(bst));
		node_b->data=data[i];
		node_b->right_child=NULL;
		node_b->left_child=NULL;

		if (*bst_==NULL)
		{
			*bst_=node_b;
		}
		else
			insert(*bst_,node_b);
		i++;
	}
	end = clock();
	bst_t= (double)(end - begin) / CLOCKS_PER_SEC;

	printf("->Filling Structures\nStructures\tStack\tQueue\tBST\nExec. time\t%.3f\t%.3f\t%.3f\n",stack_t*1000.0,queue_t*1000.0,bst_t*1000.0);// X1000 convert to second to milisecond
	
	i=0;
}
void ordered_print(stack * stack_, queue * queue_, bst * bst_)
{
	int i,j,k,swapped=0;
	stack *current_p, *previous_p=NULL,*iter_s=stack_;
	queue *current_q, *previous_q=NULL,*iter_q=queue_;
	clock_t begin, end;
	double stack_t,queue_t,bst_t;
	printf("\n->Printing ordered Structures\nStack:\t");
	begin = clock();	
	while(swapped!=1)
	{
		swapped=1;
		current_p=stack_;
		previous_p=NULL;
		while(current_p!=NULL)
		{
			if (previous_p!=NULL)
			{
				if (current_p->data>previous_p->data)
				{
					swap_s(current_p,previous_p);
					swapped=0;
				}
			}
			previous_p=current_p;
			current_p=current_p->next;
		}
	}

	while(iter_s!=NULL)
	{
		printf(" %d ",iter_s->data );
		iter_s=iter_s->next;
	}
	end = clock();
	stack_t= (double)(end - begin) / CLOCKS_PER_SEC;

	swapped=0;
	printf("\nQueue:\t");
	
	begin = clock();	
	while(swapped!=1)
	{
		swapped=1;
		current_q=queue_;
		previous_q=NULL;
		while(current_q!=NULL)
		{
			if (previous_q!=NULL)
			{
				if (current_q->data>previous_q->data)
				{
					swap_q(current_q,previous_q);
					swapped=0;
				}
			}
			previous_q=current_q;
			current_q=current_q->next;
		}
	}

	while(iter_q!=NULL)
	{
		printf(" %d ",iter_q->data );
		iter_q=iter_q->next;
	}
	end = clock();
	queue_t= (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\nBST:\t");

	begin = clock();	
	inorder(bst_);
	end = clock();
	bst_t= (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nStructures\tStack\tQueue\tBST\nExec. time\t%.3f\t%.3f\t%.3f\n\n",stack_t*1000.0,queue_t*1000.0,bst_t*1000.0);// X1000 convert to second to milisecond
}
void swap_s(stack *previous, stack * current)
{
	stack *temp=(stack*)malloc(sizeof(stack));

	temp->data=previous->data;
	previous->data=current->data;
	current->data=temp->data;

	free(temp);
}
void swap_q(queue *previous, queue * current)
{
	queue *temp=(queue*)malloc(sizeof(queue));

	temp->data=previous->data;
	previous->data=current->data;
	current->data=temp->data;

	free(temp);
}
void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search)
{
	int found_number=0,step=0,i=0;
	stack * iter_s=stack_;
	queue *iter_q=queue_;
	val_to_search=23;
	clock_t begin, end;
	double stack_t,queue_t,bst_t;
	printf("->Search with Structures\n");
	
	begin = clock();
	while(iter_s!=NULL)
	{
		if (iter_s->data==val_to_search)
		{
			found_number++;
			step+=i+1;
			i=0;
		}
		else
			i++;
		iter_s=iter_s->next;
	}
	if (found_number==0)
		printf("There is no %d in the stack.\n",val_to_search );
	else
	printf("Stack->\t%d result founded on %d. step.\n",found_number,step);
	end = clock();
	stack_t= (double)(end - begin) / CLOCKS_PER_SEC;

	found_number=0;
	step=0;
	i=0;

	begin = clock();
	while(iter_q!=NULL)
	{
		if (iter_q->data==val_to_search)
		{
			found_number++;
			step+=i+1;
			i=0;
		}
		else
			i++;

		iter_q=iter_q->next;
	}
	if (found_number==0)
		printf("There is no %d in the queue.\n",val_to_search );
	else
	printf("Queue->\t%d result founded on %d. step.\n",found_number,step);
	end = clock();
	queue_t= (double)(end - begin) / CLOCKS_PER_SEC;


	step=0;
	i=1;
	found_number=0;
	begin = clock();
	search_b(bst_,val_to_search,&step,&found_number,&i);
	printf("BST->\t%d result founded on %d. step.\n",found_number,step);
	end = clock();
	bst_t= (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Structures\tStack\tQueue\tBST\nExec. time\t%.3f\t%.3f\t%.3f\n\n",stack_t*1000.0,queue_t*1000.0,bst_t*1000.0);// X1000 convert to second to milisecond
}
void search_b(bst *root, int x,int *step, int *found_number,int *i)			//searching in binary
{
	if (root==NULL)
	{
		return;
	}
    else if(root->data==x)
    {
        *found_number+=1;
		*step+=*i;
		*i=1;
		search_b(root->left_child, x, step,found_number,i);
    }
    else if(x>root->data)
    {
    	*i+=1;			//increeasing step number
        search_b(root->right_child, x, step,found_number,i);
    }
    else
    {
    	*i+=1;			//increeasing step number
		search_b(root->left_child, x, step,found_number,i);
    }
}
void special_traverse(stack * stack_, queue * queue_, bst * bst_)
{

	double_lnkd_lst * head=NULL, *tail_d_l,* iter_d_l, *new_node,*temp;
	stack * iter_s= stack_;
	queue * iter_q= queue_;
	int max, min,finish=0;
	clock_t begin, end;
	double stack_t,queue_t,bst_t;
	begin = clock();
	
	printf("->Special Traverse with Structures\nStack->\t");
	//firstly pass the stack datas to double linked list
	while(iter_s!=NULL)
	{
		new_node=(double_lnkd_lst*)malloc(sizeof(double_lnkd_lst));
		new_node->data=iter_s->data;
		new_node->previous=NULL;
		new_node->next=NULL;

		if (head==NULL)
		{
			head=new_node;
			tail_d_l=new_node;
		}
		else
		{
			new_node->previous=tail_d_l;
			tail_d_l->next=new_node;
			tail_d_l=new_node;
		}

		iter_s=iter_s->next;
	}

	iter_d_l=head;

	while(finish!=1)
	{
		printf(" %d ",iter_d_l->data );
		temp=iter_d_l;
		if (iter_d_l->next==NULL)
		{
			finish=1;
		}
		else
		{
			iter_d_l=iter_d_l->next;
			iter_d_l->previous=NULL;
			free(temp);
			printf(" %d ",tail_d_l->data );
			temp=tail_d_l;
			if (tail_d_l->previous==NULL)
			{
				finish=1;
			}
			else
			{
				tail_d_l=tail_d_l->previous;
				tail_d_l->next=NULL;
				free(temp);
			}
		}
	}
	end = clock();
	stack_t= (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nQueue->\t");
	//pass the queue datas to double linked list for special traverse
	head=NULL;
	begin= clock();
	while(iter_q!=NULL)
	{
		new_node=(double_lnkd_lst*)malloc(sizeof(double_lnkd_lst));
		new_node->data=iter_q->data;
		new_node->previous=NULL;
		new_node->next=NULL;

		if (head==NULL)
		{
			head=new_node;
			tail_d_l=new_node;
		}
		else
		{
			new_node->previous=tail_d_l;
			tail_d_l->next=new_node;
			tail_d_l=new_node;
		}

		iter_q=iter_q->next;
	}

	iter_d_l=head;
	finish=0;
	while(finish!=1)
	{
		printf(" %d ",iter_d_l->data );
		temp=iter_d_l;
		if (iter_d_l->next==NULL)
		{
			finish=1;
		}
		else
		{
			iter_d_l=iter_d_l->next;
			iter_d_l->previous=NULL;
			free(temp);
			printf(" %d ",tail_d_l->data );
			temp=tail_d_l;
			if (tail_d_l->previous==NULL)
			{
				finish=1;
			}
			else
			{
				tail_d_l=tail_d_l->previous;
				tail_d_l->next=NULL;
				free(temp);
			}
		}
	}
	end=clock();
	queue_t= (double)(end - begin) / CLOCKS_PER_SEC;

	//pass to data of bst to double linked list

	printf("\nStructures\tStack\tQueue\tBST\nExec. time\t%.3f\t%.3f\n\n",stack_t*1000.0,queue_t*1000.0);// X1000 convert to second to milisecond
}
