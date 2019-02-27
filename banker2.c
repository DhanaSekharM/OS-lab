#include<stdio.h>
#include<stdlib.h>

void print(int x[][10],int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<m;j++){
			printf("%d\t",x[i][j]);
		}
	}	
}

//Resource Request algorithm
void res_request(int allocation[10][10], int need[10][10], int available[10], int pid, int m)
{
	int reqmat[10];
	int i;
	printf("Enter additional request :- \n");
	for(i=0; i < m; i++)
	{
		//printf(" Request for resource %d : ",i+1);
		scanf("%d",&reqmat[i]);
	}
	
	// for(i=0;i<m;i++)
	// 	if(reqmat[0][i] > need[pid][i]){
	// 		printf("\n Error encountered.\n");
	// 		exit(0);
	// }

	for(i = 0; i < m; i++)
	{
		if(reqmat[i] > available[i] || reqmat[i] > need[pid][i])
		{
			printf("Resources unavailable, process has to wait\n");
			//exit(0);
		}
	}
	
	if(i == m)
	{
		for(i = 0; i < m; i++)
		{
			available[i] -= reqmat[i];
			allocation[pid][i] += reqmat[i];
			need[pid][i] -= reqmat[i];
		}
	}
}

//Safety algorithm
int safety(int allocation[][10], int need[][10], int available[], int n, int m, int a[]){

	int i,j,k,x=0;
	int finish[10] ,work[10];
	int pflag=0,flag=0;
	for(i=0; i<n; i++)
		finish[i] = 0;

	for(i=0; i<m; i++)
		work[i] = available[i];

	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		{
			if(finish[i] == 0)
			{
				flag=0;
				for(j=0; j<m; j++)
				{
					if(need[i][j] > work[j])
						flag=1;
				}
				if(flag == 0 && finish[i] == 0)
				{
					for(j=0; j<m; j++)
						work[j] += allocation[i][j];
					finish[i] = 1;
					pflag++;
					a[x++] = i;
				}
			}
		}
		if(pflag == n)
			return 1;
	}
	return 0;
}


//Banker's Algorithm
void accept(int allocation[][10] ,int need[][10], int max[10][10], int work[10],int *n,int *m)
{
	int i,j;
	printf("Enter total no. of processes : ");
	scanf("%d",n);

	printf("Enter total no. of resources : ");
	scanf("%d",m);
 	
 	printf(" Allocation matrix : \n");
	for(i = 0; i <* n; i++)
	{
		for(j = 0; j <* m; j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}

	printf(" Maximum matrix : \n");
	for(i = 0; i <* n; i++)
	{
		for(j = 0; j <* m; j++)
		{
			scanf("%d",&max[i][j]);
		}
	}

	if(flag)
	{
		printf("Available resources : \n");
	
		for(i = 0; i <* m; i++)
		{
			scanf("%d",&work[i]);
		}
	}

	for(i=0;i<*n;i++)
		for(j=0;j<*m;j++)
			need[i][j] = max[i][j] - allocation[i][j];

	// printf("\n Allocation Matrix");
	// print(A,*n,*m);
	// printf("\n Maximum Requirement Matrix");
	// print(M,*n,*m);
	// printf("\n Need Matrix");
	// print(N,*n,*m);

}

int banker(int allocation[][10],int need[][10],int work[10],int n,int m){
	int j,i,a[10];
	j = safety(allocation, need, work, n, m, a);
	if(j != 0 )
	{
		printf("\n\n");
		for(i=0;i<n;i++)
		     printf(" P%d  ",a[i]);
		printf("A safety sequence has been detected.\n");
		return 1;
	}
	else
	{
		printf("Deadlock has occured.\n");
		return 0;
	}
}


void main(){
	int ret;
	int allocation[10][10];
	int max[10][10];
	int need[10][10];
	int available[10];
	int n, m, pid, ch, i, j;
	int flag = 1
	accept(allocation,need,max,available,&n,&m, flag);
	//ret = banker(allocation,need,work,n,m);
	while(1)
	{
		printf("Do you want make an 1.additional request 2.New requests 3.check 4.exit? \n");
		scanf("%d",&ch);
		if(ch == 1)
		{
			printf("Enter process no. : \n");
			scanf("%d",&pid);
			res_request(allocation, need , available, pid, m);
			//ret = banker(allocation ,need, work , n ,m);
			// if(ret == 0 )
			// 	exit(0);
		}
		else if(ch == 2)
		{
			// int n = 0;
			// printf("Enter process id \n");
			// scanf("%d", &new);
			// printf("Enter allocation vector\n");
			// for(i = 0; i < m; i++)
			// 	scanf("%d", &allocation[new][i]);

			// if(new >= n)
			// {
			// 	printf("Enter Maximum vector\n");
			// 	for(i = 0; i < m; i++)
			// 		scanf("%d", &max[new][i]);
			// }

			// for(i = 0; i < m; i++)
			// 	need[new][i] = max[new][i] - allocation[new][i];
			// n++;
			accept(allocation, need, max, available, &n, &m, 0);

		}
		else if(ch == 3)
		{
			ret = banker(allocation, need, available, n, m);
		}
		else
			break;
	}



}