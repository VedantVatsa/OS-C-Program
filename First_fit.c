#include <stdio.h>
int main()
{
int n,b;
printf("Enter no of processes: ");
scanf("%d",&n);
int process_size[n];
for(int i=0;i<n;i++)
{
printf("Enter size of %d process: ",i+1);
scanf("%d",&process_size[i]);
}
printf("Enter Total No of Blocks: ");
scanf("%d",&b);
int block_size[b];
int c[n];
for(int i=0;i<b;i++){
printf("Enter size Of %d block: ",i+1);
scanf("%d",&block_size[i]);
}
printf("Process\tProcess size\tBlockSize\tWaste\n");
for(int i=0;i<n;i++)
{
for(int j=0;j<b;j++)
{
if(process_size[i]<=block_size[j]){
printf("%d\t\t%d\t\t%d\t\t%d",i+1,process_size[i],block_size[j],block_size[j]-
process_size[i]);
printf("\n");
block_size[j]=-1;
c[i]=i+1;
break;
}
else if(j==4)
{
printf("Unallocate %d\n",i+1);
}
}
}
return 0;
}
