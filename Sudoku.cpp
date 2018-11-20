#include <iostream>
#define SIZE 9
using namespace std;

int sudoku[SIZE*SIZE];
int solution(int,int);
int solution(int);
void print()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            cout<<sudoku[i*9+j]<<" ";
        }
        cout<<endl;
    }
}
bool compatible(int,int);

bool compatible(int r,int n)
{
    int row=1,col=1,block=1;
    int cl = r%9;
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(n == sudoku[i*9+cl])
        {
            row = 0;
            return false;
        }
    }
    int rw = r/9;
    rw*=9;
    for(i=0;i<SIZE;i++)
    {
        if(n == sudoku[rw+i])
        {
            col = 0;
            return false;
        }
    }
    if((r>=0 && r<=2) || (r>=9 && r<=11) || (r>=18 && r<=20))
    {
        for(i=0;i<=2;i++)
        {
            if( n == sudoku[i])
             {   return false;}
        }
        for(i=9;i<=11;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
        for(i=18;i<=20;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
    }
    if((r>=3 && r<=5) || (r>=12 && r<=14) || (r>=21 && r<=23))
    {
        for(i=3;i<=5;i++)
        {
            if( n == sudoku[i])
             {   return false;}
        }
        for(i=12;i<=14;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
        for(i=21;i<=23;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
    }
    if((r>=6 && r<=8) || (r>=15 && r<=17) || (r>=24 && r<=26))
    {
        for(i=6;i<=8;i++)
        {
            if( n == sudoku[i])
             {   return false;}
        }
        for(i=15;i<=17;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
        for(i=24;i<=26;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
    }
    if((r>=27 && r<=29) || (r>=36 && r<=38) || (r>=45 && r<=47))
    {
        for(i=27;i<=29;i++)
        {
            if( n == sudoku[i])
             {   return false;}
        }
        for(i=36;i<=38;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
        for(i=45;i<=47;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
    }
    if((r>=30 && r<=32) || (r>=39 && r<=41) || (r>=48 && r<=50))
    {
        for(i=30;i<=32;i++)
        {
            if( n == sudoku[i])
             {   return false;}
        }
        for(i=39;i<=41;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
        for(i=48;i<=50;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
    }
    if((r>=33 && r<=35) || (r>=42 && r<=44) || (r>=51 && r<=53))
    {
        for(i=33;i<=35;i++)
        {
            if( n == sudoku[i])
             {   return false;}
        }
        for(i=42;i<=44;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
        for(i=51;i<=53;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
    }
    if((r>=54 && r<=56) || (r>=63 && r<=65) || (r>=72 && r<=74))
    {
        for(i=54;i<=56;i++)
        {
            if( n == sudoku[i])
             {   return false;}
        }
        for(i=63;i<=65;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
        for(i=72;i<=74;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
    }
    if((r>=57 && r<=59) || (r>=66 && r<=68) || (r>=75 && r<=77))
    {
        for(i=57;i<=59;i++)
        {
            if( n == sudoku[i])
             {   return false;}
        }
        for(i=66;i<=68;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
        for(i=75;i<=77;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
    }
    if((r>=60 && r<=62) || (r>=69 && r<=71) || (r>=78 && r<=80))
    {
        for(i=60;i<=62;i++)
        {
            if( n == sudoku[i])
             {   return false;}
        }
        for(i=69;i<=71;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
        for(i=78;i<=80;i++)
        {
            if(n == sudoku[i])
            {    return false;}
        }
    }
    
    return true;
}

int solution(int r)
{
       
    
        if(solution(r,1))
            return 1;
        if(solution(r,2))
            return 1;
        if(solution(r,3))
            return 1;
        if(solution(r,4))
            return 1;
        if(solution(r,5))
            return 1;
        if(solution(r,6))
            return 1;
        if(solution(r,7))
            return 1;
        if(solution(r,8))
            return 1;
        if(solution(r,9))
            return 1;
        
        sudoku[r] = 0;
        return 0;
}

int solution(int r,int n)
{
    
    if(compatible(r,n))
    {
        sudoku[r] = n;
        int i=0;
          while(sudoku[r+i] != 0 && (r+i)<(SIZE*SIZE))		//finding the next empty box
          {
              i++;
          }
          
          if(r+i == SIZE*SIZE)		
            return 1;
         
        if(solution(r+i,1))
            return 1;
        if(solution(r+i,2))
            return 1;
        if(solution(r+i,3))
            return 1;
        if(solution(r+i,4))
            return 1;
        if(solution(r+i,5))
            return 1;
        if(solution(r+i,6))
            return 1;
        if(solution(r+i,7))
            return 1;
        if(solution(r+i,8))
            return 1;
        if(solution(r+i,9))
            return 1;
        
        sudoku[r] = 0;
        return 0;
    }
    
    return 0;
}

int main() 
{
	cout<<"Enter Sudoku (0 -> Empty):"<<endl;
	int i,j,k,l;
	int zero_count=0;
	for(i=0;i<SIZE*SIZE;i++)
	{
	    cin>>sudoku[i];
	    if(sudoku[i] == 0 && zero_count<1)
	    {
	        k = i;
	        ++zero_count;
	    }
	}
	if(solution(k))
	{
	    cout<<"Answer:"<<endl;
	    print();
	}
	else
	    cout<<"No solution"<<endl;
	
	return 0;
}
