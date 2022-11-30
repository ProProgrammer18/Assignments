#include<stdio.h>
#include<mpi.h>
#include<limits.h>

int main(int argc,char **argv)
{
  int vote_gain = 1000,num_procs,rank,max=INT_MIN,aspect=0;
  int row=4,col=4;
  int sum[4] = {0};

  int adv[4][4] = {{-2,5,3,6},{8,2,-5,-2},{1,3,10,4},{10,6,-2,5}};  

//   for (int i = 0; i < row; i++)
//   {
//     for (int j = 0; j < col; j++)
//     {
//         scanf("%d",&adv[i][j]);
//     }
//   }
  

  MPI_Init(&argc,&argv);
  
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&num_procs);
  
//   int j = rank;
    printf("%d\n",rank);

  for (int i = 0; i < 4; i++)
  {
    sum[rank]+=adv[rank][i];
  }

  MPI_Finalize();

  for (int i = 0; i < 4; i++)
  {
    if(sum[i]>max)
    {
        max = sum[i];
        aspect = i;
    }
  }

  printf("For maximum votes i.e. %d one should focus on advertising more on %d aspect\n",max*vote_gain,aspect+1);

return 0;
}