#include<iostream>
 
using namespace std;
 
int main() {
   int  dinh, k, canh;
   cin>> canh;
   dinh=canh+1;
   int CANH[canh][2],DINH[dinh]={0};
   for (int i = 0; i < canh; i++){
   	cin>>CANH[i][0];
   	cin>>CANH[i][1];
   	DINH[CANH[i][0]]++;
   	DINH[CANH[i][1]]++;
   }
   while(DINH[0]!=0){
   for(int i=1;i<dinh;i++){
   	if(DINH[i]==1){
   		for(int j=0;j<canh;j++){
   			if((i==CANH[j][0])&&(DINH[CANH[j][1]]>0)){
   				DINH[CANH[j][1]]--;
   				DINH[CANH[j][0]]--;
   				if(DINH[0]==0)
   					break;
   				cout<<CANH[j][1]<<" ";
   			}
   			if((i==CANH[j][1])&&(DINH[CANH[j][0]]>0)){
   				DINH[CANH[j][0]]--;
   				DINH[CANH[j][1]]--;
   				if(DINH[0]==0)
   					break;
   				cout<<CANH[j][0]<<" ";
   			}
   		}
   		i=1;
	   }
   }
 }
return 0;
}
