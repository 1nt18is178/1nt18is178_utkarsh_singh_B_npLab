#include<stdio.h>
#include<string.h>
int str1[30];
int j;
void sender(int data[25],int data_length);
void reciver(int data[25],int data_length);

int main(){

	int data[25];

	int data_length;
	printf("enter size of frame\n");
	scanf("%d",&data_length);
	int i;
	printf("enter your data\n");
	for(i=0;i<data_length;i++){
	scanf("%d",&data[i]);
	}
	printf("before bit stuffing:  ");
	for(i=0;i<data_length;i++){
	printf("%d",data[i]);
	}
	sender(data,data_length);
	reciver(str1,j);
	//reciver(data,data_length);
return 0;
}
void sender(int data[25],int data_length){
	int i=0;
	j=0;
	int count=1;
	while(i<data_length){
	if(data[i]==0){
	str1[j]=data[i];
	}
	else{
		str1[j]=data[i];
		for(int k=i+1;data[k]==1 && k<data_length && count<5;k++){
			j++;
			str1[j]=data[k];
			count++;

			if(count==5){
			j++;
			str1[j]=0;
			}
			i=k;
		}
		}
	i++;
	j++;
	}
	printf("\nafter bit stuffing:  ");
	i=0;
	for(i=0;i<j;i++){
	printf("%d",str1[i]);
	}
}
void reciver(int data[25],int data_length){

	int m=0,i=0;
	int count=0;
	int str2[20];
	while(i<data_length){
	if(data[i]==0){
	str2[m]=data[i];
	}
	else{
		str2[m]=data[i];
		for(int k=i+1;data[k]==1 && k<data_length && count<4;k++){
			m++;
			str2[m]=data[k];
			count++;

			if(count==4){
			m++;
			if(data[m]==0 && data[m+1]==1)
				k=k+1;
				m--;
				}
			i=k;
		}
		}
	i++;
	m++;
	}
	printf("\nafter bit unstuffing:  ");
	i=0;
	for(i=0;i<m;i++){
	printf("%d",str2[i]);
	}
	printf("\n");
}
