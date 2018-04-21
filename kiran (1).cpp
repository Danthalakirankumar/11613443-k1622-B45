#include <stdio.h>
#include<conio.h>
int main()
{
	float Btime[100],Wt=1,Tat=0,Sum_Wt=0,Sum_Tat,n_Wt=0,n_Tat=0,Atime[100];
	float extra,A1time,extra0,B1time,graph=0.0;
	int n,i,j,temp=0,p=1,index,temp1;
	printf("How many processes do you want to enter:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf(" Please enter the burst time and arrival time for %d:",i+1);
	    scanf("%f %f",&extra0,&extra);
		if(extra!=1.0)
		{
			Btime[i]=extra0;
			Atime[i]=extra;
		}
		else 
		{
	
		A1time=extra;
		B1time=extra0;
		index=i;
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			if(Btime[i]>Btime[j])
			{
				temp=Btime[i];
				temp1=Atime[i];
				Btime[i]=Btime[j];
				Atime[i]=Atime[j];
				Btime[j]=temp;
				Atime[j]=temp1;
			}
		}
	}
/*	for(i=0;i<n-1;i++)
	printf("\n%f		%f\n",Btime[i],Atime[i]*/
	printf("Pid\tBursttime\tWt\tTurnAroundTime");
	while(p)
	{
		graph=1.0+B1time; // graph index
	//	printf("%f",A1time);
	
		Wt=graph-(A1time+B1time); //waiting time of process
		printf("\n%d",index);
		printf("	%f",B1time);
		
		printf("	%f",Wt);
		printf("	%f",(graph-A1time)); // turn around time
	//	printf("\n%d\t\t%f\t\t%f\t\t%f",index+1,Btime[index],Wt,Tat);
		Sum_Tat=Sum_Tat+(graph-A1time); // sum of turn around time
		p=p-1;
	}
//	printf("\n%f\n",graph);
	for(j=0;j<n-1;j++)
	{ Wt=graph-Atime[j];
		graph=graph+Btime[j];
		//
		printf("\n%d",j);
		printf("	%f",Btime[j]);
		
		printf("	%f",Wt);
		printf("	%f",(graph-Atime[j]));
			}
	
	

	n_Wt=Sum_Wt/n;
		n_Tat=Sum_Tat/n;
	printf("\nthe average waiting time is %f",n_Wt);
	printf("\nthe average turn around time is %f",n_Tat);
	
	getch();
}
