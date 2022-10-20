#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pid,at,bt,ct,wt,tat;
	struct process *next;
}*current;

void add_process(int p,int a,int b)
{
	struct process *New=(struct process*)malloc(sizeof(struct process));
	struct process *temp=current;
	New->pid=p;
	New->at=a;
	New->bt=b;
	New->next=NULL;
	if(current==NULL)
	{
		current=New;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=New;
	}
}

void remove_process(int p)
{
	struct process *temp=current;
	struct process *prev=current;
	int found=0;
	while(temp!=NULL)
	{
		if(temp->pid==p)
		{
			found=1;
			if(temp==current)
			{
				current=current->next;
				free(temp);
				temp=current;
			}
			else
			{
				prev->next=temp->next;
				free(temp);
				temp=prev;
			}
		}
		prev=temp;
		temp=temp->next;
	}
	if(found==0)
	{
		printf("Process not found\n");
	}
}

void display()
{
	struct process *temp=current;
	printf("PID\tArrival Time\tBurst Time\n");
	while(temp!=NULL)
	{
		printf("%d\t%d\t%d\n",temp->pid,temp->at,temp->bt);
		temp=temp->next;
	}
}

void fcfs()
{
	struct process *temp=current;
	struct process *t,*soonest;
	int tp,ta,tb;
	int time=0;
	while(temp!=NULL)
	{
		t=temp;
		soonest=temp;
		while(t!=NULL)
		{
			if((t->at)<(soonest->at))
			{
				soonest=t;
			}
			else if((t->at)==(soonest->at))
			{
				if((t->bt)<(soonest->bt))
				{
					soonest=t;
				}
			}
			t=t->next;
		}
		tp=temp->pid;
		ta=temp->at;
		tb=temp->bt;
		temp->pid=soonest->pid;
		temp->at=soonest->at;
		temp->bt=soonest->bt;
		soonest->pid=tp;
		soonest->at=ta;
		soonest->bt=tb;
		temp=temp->next;
	}
	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
	while(current!=NULL)//removes processes one-by-one, completing fcfs
	{
		time+=current->bt;
		current->ct=time;
		current->tat=(current->ct) - (current->at);
		current->wt=(current->tat) - (current->bt);
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",current->pid,current->at,current->bt,current->ct,current->tat,current->wt);
		temp=current;
		current=current->next;
		free(temp);
	}
}

int main()
{
	int choice=1,p,a,b;
	while(choice!=0)
	{
		printf("Enter:\n\t1 to add a process to the list\n\t2 to remove a process from the list\n\t3 to display process list\n\t4 to start SJF schedule\n\t0 to EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter PID : ");
				scanf("%d",&p);
				printf("\nEnter Arrival Time : ");
				scanf("%d",&a);
				printf("Enter Burst Time : ");
				scanf("%d",&b);
				printf("\n");
				add_process(p,a,b);
				break;
			case 2:
				printf("Enter PID : ");
				scanf("%d",&p);
				printf("\n");
				remove_process(p);
				break;
			case 3:
				printf("Current process list is:\n");
				display();
				break;
			case 4:
				printf("Starting SJF schedule :\n");
				fcfs();
				break;
			case 0:
				printf("EXITING\n");
				break;
			default:
				printf("Invalid Choice\n");
				
		}
	}
	return 0;
}
