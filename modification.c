#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merging(int a[10000],int low, int mid, int high) {
   int b[20000];
   int i,j,k;
   i=low;
   j=mid+1;
   k=low;
   while(i<=mid&&j<=high)
   {
   	if(a[i]>a[j])
   	  b[k++]=a[i++];
   	else
   	  b[k++]=a[j++];

   }

   while(i <= mid)
      b[k++] = a[i++];

   while(j <= high)
      b[k++] = a[j++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int a[10000],int low, int high) {
   int mid;

   if(low < high) {
      mid = low+(high-low)/2;
      sort(a,low, mid);
      sort(a,mid+1, high);
      merging(a,low, mid, high);
   }
}

int main() {
   int i,n;
   int* a;
   clock_t time_req;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   a=(int*)malloc(n*sizeof(int));
   time_req=clock();
   for(i=0; i<20; i++)
   {
       a[i]=rand()%100;
   printf("%d  ",a[i]);
   }
   sort(a,0, n-1);
   time_req=clock() - time_req;
   printf("\nArray after sorting\n");
   for(i = 0; i <20; i++)
   printf("%d ", a[i]);
   printf("\nTime taken: %f",(float)time_req/CLOCKS_PER_SEC );
   return 0;
}
