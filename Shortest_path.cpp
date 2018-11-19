#include <iostream>
#include <vector>
#define SIZE 6

using namespace std;
vector <int> path_length;
int maze[SIZE][SIZE];
void solution (int,int);
void solution (int,int,int);
void solution(int r,int c)
{
    solution(r+1,c,1);
    solution(r,c+1,1);
    solution(r-1,c,1);
    solution(r,c-1,1);
}

void solution(int r,int c,int n)
{
    if((r==0 || r==SIZE-1 || c==0 || c==SIZE-1) && maze[r][c] == 0)
    {
        path_length.push_back(n);
    }
    if((r>0 && r<SIZE) && (c>0 && c<SIZE) && maze[r][c] == 0)
    {
        maze[r][c] = 2;
        
        solution(r+1,c,n+1);
        solution(r,c+1,n+1);
        solution(r-1,c,n+1);
        solution(r,c-1,n+1);

        maze[r][c] = 0;
    }
    
}

int main()
{
    int small;
    int i,j,k,l;
    cout<<"Enter:"<<endl;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j] == 1)
                {
                    k = i; l = j; 
                }
        }
    }
    
    solution(k,l);
    if(path_length.empty())
    {
        cout<<"No path"<<endl;
        return 0;
    }
    small = path_length[0];
    
    for(i=0;i<path_length.size();i++)
    {
        if(path_length[i]<small)
        {
            small = path_length[i];
        }
    }
    cout<<endl;
    cout<<"Answer:"<<small<<endl;
    
    return 0;
}
