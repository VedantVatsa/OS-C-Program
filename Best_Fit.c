#include <stdio.h>
int main()
{
int n,b;
printf("Enter no of process");
scanf("%d",&n);
int pr[n];
int process_size[n];
for(int i=0;i<n;i++){
printf("Enter size of %d process",i+1);
scanf("%d",&process_size[i]);
}
printf("Enter Total No of Blocks");
scanf("%d",&b);
int block_size[b];
int dn[n];
for(int i=0;i<b;i++){
printf("Enter size Of %d block",i+1);
scanf("%d",&block_size[i]);
}
printf("Process\tBlockSize\tWaste\n");
int diff=2147483647;
int index=-1;
for(int i=0;i<n;i++){
for(int j=0;j<b;j++){
if(block_size[j]-process_size[i]>=0){
if(block_size[j]-process_size[i]<diff){
diff=block_size[j]-process_size[i];
index=j;
}
}
}
if(index!=-1){
printf("%d\t\t%d\t\t%d\n",i+1,block_size[index],block_size[index]-process_size[i]);
block_size[index]=-1;
index=-1;
diff=2147483647;
}
else
{
printf("%d is Unallocated",i+1);
}
}
return 0;
}
