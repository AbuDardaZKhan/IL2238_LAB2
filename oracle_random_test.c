#include<stdio.h>
#include<stdlib.h>

#define length 15
#define no_of_testcases 281

void random_test();
//void pairwise_test();
void append(char *,int *);

int main()
{
	random_test();
	//pairwise_test();
	return 0;
	
}



void append(char *str,int *array)
{
	int i=0,j=0;
	char str1[100];
	while(*(str+j)!='\0')
	{
		for(i=0;i<15;i++)
		{
			if(*(str+i)!=' ')
			{
				str1[i]=*(str+i);	
			}
			else
				break;
		}
		*(array+j)=atoi(str1);
		j++;
	}
}

void random_test()
{
	char str1[1000],str2[100],str3[2];
	int sample[length],key,i=0,j=0,k=0,Query_result,Query_reference=0,failure=0;
	FILE *array,*keys,*memQ_result;
	array=fopen("array.txt","r");
	keys=fopen("key.txt","r");
	memQ_result=fopen("memQ.txt","r");
	for(i=0;i<no_of_testcases;i++)
	{
		fgets(str1,1000,array);
		append(str1,sample);
		fgets(str2,100,keys);
		fgets(str3,1,memQ_result);	
		key=atoi(str2);
		Query_result=atoi(str3);
		Query_reference=0;
		for(j=0;j<length;j++)
		{
			if(key==sample[j])
				Query_reference=1;
			
		}
		if(Query_reference!=Query_result)
			failure++;	
	}
	printf("Number of failures detected by random testing in test algorithm with respect to reference algorithm : %d\n",failure);
	/*failure=0;
	for(i=0;i<no_of_testcases;i++)
	{
		Query_reference=0;
		for(j=0;j<length;j++)
		{
			for(k=0;k<no_of_testcases;k++)
			{
				if(key[k]==sample[i][k])
				Query_reference=1;
			}
		}
		if(Query_reference!=Query_result[i])
			failure++;
	}
	printf("Number of failures detected by pairwise testing in test algorithm with respect to reference algorithm : %d\n",failure);*/
	fclose(array);
	fclose(keys);
	fclose(memQ_result);
}

/*void pairwise_test()
{
	int sample[no_of_testcases][length],key[no_of_testcases],i=0,j=0,k=0,Query_result[no_of_testcases],Query_reference=0,failure=0;
	FILE *array,*keys,*memQ_result;
	array=fopen("array.txt","r");
	keys=fopen("key.txt","r");
	memQ_result=fopen("memQ.txt","r");
	while(fscanf(array,"%d",&sample[i][j])!=EOF)
	{
		for(i=0;i<no_of_testcases;i++)
		{
			for(j=0;j<length;j++)
			{
				fscanf(array,"%d",&sample[i][j]);
			}
			fscanf(keys,"%d",&key[i]);
			fscanf(memQ_result,"%d",&Query_result[i]);		
		}
	}
	
	fclose(array);
	fclose(keys);
	fclose(memQ_result);
}*/ 

