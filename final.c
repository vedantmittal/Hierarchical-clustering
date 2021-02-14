#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<math.h>

int func(int a1, int a2, int b1, int b2, int c1, int c2, int d1, int d2, int e1, int e2){
    int z=((a2-a1)*(a2-a1))+((b2-b1)*(b2-b1))+((c2-c1)*(c2-c1))+((d2-d1)*(d2-d1))+((e2-e1)*(e2-e1));
    return sqrt(z);
}

struct Student{
	double sapid;
	double rollno;
	double cgpa;
	double tenth;
	double twelfth;
	double proj;
	double lang;
};

int main(){
	char buff ;  
	FILE *fp = fopen("dataaset.csv","r") ;
	int i,j,a[10000];
	char n[100];
	int count=0,total=0,line=0,dot=0,check=0,div,abc=0,fir=0,sec=0,aaaa=0,inn,common=0,bas=0,incx=0,incy=0,inc=0,store1[100],store=0,takii1=0,takii2=0,t=0,d=0,flag=0,tag=0,k,dm; 
	double l,arr[10000],m,f[100],dist[100][100],value,p[20][30],collect[100][500],duplicate=0;
	for(i=0; ;i++){
		buff= fgetc(fp);
		if(buff == EOF){
			break;
		}
		n[i]=buff;
		++total;
		if(buff==','){
			count+=1;
		}
		if(buff== '\n'){
			line+=1;
		}
	}
	
	for(i=0;i<total;i++){
		printf("%c",n[i]);
	}

	printf(" \n total:%d \t  comma:%d \t line:%d \n",total,count,line);
	
	for(i=0;i<total;i++){
		if(!(n[i]==','||n[i]=='.'||n[i]=='\n')){
			arr[i]=(int)n[i]-'0';
		}
		else{
			arr[i] = n[i];
		}
	}
	printf("\n");
	
	for(i=0;i<total;i++){
		printf("%0.0lf",arr[i]);
	}
	
	printf("\n");
	
	for(i=0;i<total;i++){
		if(arr[i]!=44 && arr[i]!=10) {
			l = arr[i];
			while(arr[i]!=44 && arr[i]!=10){
				++i;
				if(arr[i]!=44 && arr[i]!=10) {
					if(arr[i]!=46){
						m = arr[i];
						l= l*10 + m;
					}
					else{
						dot=1;
						while(arr[i]!=44 && arr[i]!=10){
						++i;	
						m = arr[i];
						l = l + (m/pow(10,dot));
						++dot;	
						}
						
					}
				}
				else{
					break;
				}
			}
		f[check]= l;
		++check;
		}
	}
	printf("\n");
	div = check/7 ;
	struct Student record[div];
	for(i=0;i<check;i++){
		record[abc].sapid = f[i];
		++i;
		record[abc].rollno = f[i];
		++i;
		record[abc].cgpa = f[i];
		++i;
		record[abc].tenth = f[i];
		++i;
		record[abc].twelfth = f[i];
		++i;
		record[abc].proj = f[i];
		++i;
		record[abc].lang = f[i];
		abc++;
	}

	for(i=0;i<div;i++)
	{
	printf("\n");
	printf("Record %d: \t",i+1);
	printf("%lf\t%lf\t%lf\t%lf\t%lf\n",record[i].cgpa,record[i].tenth,record[i].twelfth,record[i].proj,record[i].lang);
	}
	
	for( i=0;i<div;i++)
	{
		for( j=0;j<div;j++)
		{
			dist[i][j]=func(record[i].cgpa,record[j].cgpa,record[i].tenth,record[j].tenth,record[i].twelfth,record[j].twelfth,record[i].proj,record[j].proj,record[i].lang,record[j].lang);
		}
	}
	for(i=0;i<div;i++){
		for(j=0;j<div;j++){
			collect[i][j]=-1;
		}
	}
	printf("\n");
	bas = line;
	printf("\n");
	
	scanf("%d",&inn);
	

	if(inn>=1){
		for( i=0;i<div-common;i++){
			printf("Sap: %0.0lf \t Roll No: %0.0lf \t", record[i].sapid,record[i].rollno);
			for(j=0;j<div-common;j++){
				if(i>=j){
					printf("%0.2lf \t",dist[i][j]);
				}
			}
			printf("\n");
		}	
		while(bas!=inn){
			value = dist[1][0];
			printf("\n \n");
			for( i=0;i<div-common;i++){
				for(j=0;j<div-common;j++){
					if(i>=j){
						printf("%0.2lf \t",dist[i][j]);
					}
					if(i>j){
						if(value>=dist[i][j]){
							value = dist[i][j];
							if(i<j){
								fir = j;
								sec =i;
							}
							else{
								fir =i;
								sec =j;
							}
						
						}
					}
				}
			printf("\n");
			}
			store1[store]=fir;
			t=store1[store];
			++store;
			store1[store]=sec;
			d=store1[store];
			++store;
			for(i=0;i<inn;i++){
				flag=0;
				for(j=0;j<div;j++){
					if(collect[i][j]!=-1){
						if(collect[i][j]==record[t].sapid){
							flag=1;
							incx=0;
							incy=0;
							while(collect[incx][incy]!=record[d].sapid){
								++incx;
								++incy;
								if(incx>inn){
									incx=i;
									break;
								}
							}
							if(incx>=i){
								while(collect[i][j]!=-1){
									++j;
								}
								if(collect[incx][incy]==record[d].sapid){
									incy=0;
									while(collect[incx][incy]!=-1){
										collect[i][j]= collect[incx][incy];
										++incy;
										++j;
									}
									goto even;
								}
								else{
									collect[i][j]=record[d].sapid;
									goto odd;
								}	
							}
							else{
								while(collect[i][j]!=-1){
									++j;
								}
								if(collect[incx][incy]==record[d].sapid){
									while(collect[incx][incy]!=-1){
										++incy;
									}
									j=0;
									while(collect[i][j]!=-1){
										collect[incx][incy]= collect[i][j];
										++incy;
										++j;
									}
									goto even;
								}
								else{
									collect[i][j]=record[d].sapid;
									goto odd;
								}
							}	
						}
						if(collect[i][j]==record[d].sapid){
							flag=1;
							incx=0;
							incy=0;
							while(collect[incx][incy]!=record[t].sapid){
								++incx;
								++incy;
								if(incx>inn){
									incx=i;
									break;
								}
							}
							if(incx>=i){
								while(collect[i][j]!=-1){
									++j;
								}
								if(collect[incx][incy]==record[t].sapid){
									incy=0;
									while(collect[incx][incy]!=-1){
										collect[i][j]= collect[incx][incy];
										++incy;
										++j;
									}
									goto even;
								}
								else{
									collect[i][j]=record[t].sapid;
									goto odd;
								}	
							}
							else{
								while(collect[i][j]!=-1){
									++j;
								}
								if(collect[incx][incy]==record[t].sapid){
									while(collect[incx][incy]!=-1){
										++incy;
									}
									j=0;
									while(collect[i][j]!=-1){
										collect[incx][incy]= collect[i][j];
										++incy;
										++j;
									}
									goto even;
								}
								else{
									collect[i][j]=record[t].sapid;
									goto odd;
								}
							}	
						}
					}
					if(i==inn-1){
						if(flag==0){
							i=0;
							while(collect[i][0]!=-1){
								++i;
							}
							collect[i][j]=record[t].sapid;
							collect[i][j+1]=record[d].sapid;
						}
						goto odd;
					}
				}
			}
			even:
				printf("jii \n");
				goto add;
				
			odd:
				printf("hiii \n");
				
			add:
			printf("Combining %d row and %d column \n",fir,sec);
			printf("Result Combination will be: \n");
			for(j=0;j<div-common;j++){
				if(dist[fir][j]>dist[sec][j]){
					dist[fir][j]=dist[sec][j];
					dist[j][fir]= dist[sec][j];
					printf("%0.0lf \n",dist[sec][j]);
				}
				else{
					dist[sec][j]=dist[fir][j];
					dist[j][sec]= dist[fir][j];
					printf("%0.0lf \n",dist[fir][j]);
				}
			}
			
			printf("Original Euclidean Matrix \n");
			for(i=0;i<div-common;i++){
				for(j=0;j<div-common;j++){
					printf("%0.0lf \t",dist[i][j]);
				}
				printf("\n");
			}
			printf("\n Updated Euclidean Matrix: COMBined %d and %d \n",sec,fir);
			printf("Two row and two column are combined, Result in reduced matrix: \n");
			for(i=0;i<div-common-1;i++){
				for(j=0;j<div;j++){
					if(i>=fir){
						dist[i][j]=dist[i+1][j];
					}
				}
			}
			for(i=0;i<div-common-1;i++){
				for(j=0;j<div-common-1;j++){
					if(j>=fir){
						dist[i][j]=dist[i][j+1];
					}
				}
			}
			printf("\n \n"); 
			for(i=0;i<div-common-1;i++){
				for(j=0;j<div-common-1;j++){
					printf("%0.0lf \t",dist[i][j]);
				}
			printf("\n");
			}
			printf("\n");
			bas-=1;
			common+=1;
		}
		for(i=0;i<inn;i++){
			for(j=0;j<div;j++){
				if(collect[i][j]!=-1){
					incy=j+1;
					incx=257;
					while(collect[i][incy]!=-1){
						if(collect[i][j]==collect[i][incy]){
							collect[i][incy]=collect[i][incy] + incx;
							++incx;
						}
						++incy;
					}
				}
			}
		}
		for(i=0;i<=store-2;i=i+2){
			takii1 = store1[i];
			takii2 = store1[i+1];
			printf("Operation %d: \n",i/2);
			printf("Sap: %0.0lf \t Roll No: %0.0lf \n", record[takii1].sapid,record[takii1].rollno);
			printf("Sap: %0.0lf \t Roll No: %0.0lf \n", record[takii2].sapid,record[takii2].rollno);
			printf("\n");
		}
		printf("\n \n");
		for(i=0;i<inn;i++){ 
			printf("Cluster %d: \n",i+1);
			for(j=0;j<div;j++){
				if(collect[i][j]!=-1){
					printf(" %0.0lf \n",collect[i][j]);
				}
			}
			printf("\n \n \n ");
		}
	}
	else{
		printf("Invalid Input \n Try again for range 1-6");
	}
}




