
/*@JUDGE_ID: 7008MR 586 C++*/

#include<stdio.h>
#include<string.h>

int i,j,k,l,m,n,times;
char str[20];
int time[11];

int stoi(char*s){
	int i,k=0;
	for(i=0;s[i]!=0;i++)
		k=k*10+s[i]-'0';
	return k;
}

void add(int*out,int k){
	out[0]+=k;
}

void addn(int*out,int*k){
	for(int i=0;i<=10;i++)
		out[i]+=k[i];
}

void mul(int*out,int k){
	for(int i=0;i<=10;i++)
		out[i]*=k;
}

void muln(int*out){
	for(int i=10;i>0;i--)
		out[i]=out[i-1];
	out[0]=0;
}

void count(int*out){
	int time[11];
	int i,k;
	for(i=0;i<=10;i++)
		out[i]=0;
	while(1){
		scanf("%s",str);
		if(strcmp(str,"END")==0)
			break;
		if(strcmp(str,"OP")==0){
			scanf("%d",&k);
			add(out,k);
			continue;
		}
		scanf("%s",str);
		if(str[0]=='n'){
			count(time);
			muln(time);
			addn(out,time);
		}
		else{
			k=stoi(str);
			count(time);
			mul(time,k);
			addn(out,time);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(times=1;times<=n;times++){
		scanf("%s",str);
		count(time);
		i=10;
		while(1){
			if(time[i]!=0)break;
			if(i==0)break;
			i--;
		}
		printf("Program #%d\n",times);
		printf("Runtime = ");
		if(i==0){
			printf("%d\n\n",time[0]);
			continue;
		}
		if(time[i]>1)
			printf("%d*",time[i]);
		printf("n");
		if(i>1)
			printf("^%d",i);
		for(i--;i>=0;i--){
			if(time[i]==0)continue;
			printf("+");
			if(time[i]>1||i==0){
				printf("%d",time[i]);
				if(i>0)
					printf("*");
			}
			if(i>0){
				printf("n");
				if(i>1)
					printf("^%d",i);
			}
		}
		printf("\n\n");
	}
	return 0 ;
}
