
// rat maze

#include<iostream>
#define SIZE 5
int maze[SIZE][SIZE];

using namespace std;
void print();
void print()
{
	int i,j;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
}

int findpath(int r, int c, int dr, int dc)
{
	if((r>=0 && r<SIZE) && (c>=0 && r<SIZE) && (maze[r][c] != 9) && (maze[r][c] == 2))
	{
		maze[r][c] = 7;
		return 1;
	}
	if((r>=0 && r<SIZE) && (c>=0 && r<SIZE) && (maze[r][c] != 9))
	{
		maze[r][c] = 7;
		
		if(findpath(r+1,c,dr,dc))
			return 1;
		if(findpath(r,c+1,dr,dc))
			return 1;
		maze[r][c] = 0;
		return 0;
	}
	
	return 0;
}

int main()
{
	//int size;
	//cout<<"Enter maze size:";
	//cin>>size;
	//cout<<endl;
	//int maze[size][size];
	int i,j,k,l,m,n;
	cout<<"Enter maze( 1->rat , 2->destination , 0->free path , 9->dead end):"<<endl;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			cin>>maze[i][j];
			if(maze[i][j] == 1)
			{	k = i; l = j;}
			if(maze[i][j] == 2)
			{	m = i; n = j;}
		}
	}
	cout<<k<<" "<<l<<endl;
	cout<<m<<" "<<n<<endl;
	if(findpath(k,l,m,n))
		print();
	else
		cout<<"No solution"<<endl;
		
	return 0;
}

