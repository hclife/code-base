//Deque STL
#include <iostream>
#include <deque> 
using namespace std;
int find_max_pos(int s[],int start,int end) {
    int pos=start;
    for (register int i=start+1;i<end;++i)
        if (s[pos]<=s[i]) pos=i;
    return pos;
}
void printKMax(int s[],int n,int k){
    int pos=find_max_pos(s,0,k);cout<<s[pos]<<' ';
    for (register int head=1,tail=k;tail<n;++head,++tail) {
        if (pos==head-1) pos=find_max_pos(s,head,tail);
        if (s[pos]<=s[tail]) pos=tail;cout<<s[pos]<<' ';
    }
    cout<<endl;
}
int main(){
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}