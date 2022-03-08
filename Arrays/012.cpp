#include<iostream>
using namespace std;

int main() {


    int n;
    int flag =0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int leftsum =0;
         int sum = 0;
         for(int i=0;i<n;i++) {
             sum+= arr[i];
         }
         
         
         for(int i=0;i<n;i++) {
             sum =  sum - arr[i];
             
             if(sum == leftsum)  {
                 printf("%d",arr[i]);
                 flag =1;
                 break;
             }
             leftsum = leftsum + arr[i];
         }
       
        


    return 0;
}