#include<stdio.h>
#include<stdlib.h>

#define length 15 
#define no_of_testcases 100000

void sort(int *);
int memQ(int *,int);
void append(char *,int *);

int main()
{
	
	char str1[500],str2[20];
	int sample[length],key,i=0,j=0,Query;
	FILE *array,*keys,*memQ_result;
	array=fopen("array.txt","r");
	keys=fopen("key.txt","r");
	memQ_result=fopen("memQ.txt","w");
	for(i=0;i<no_of_testcases;i++)
	{
		fgets(str1,500,array);
		append(str1,sample);
		fgets(str2,20,keys);
		key=atoi(str2);	
		sort(sample);
		Query=memQ(sample,key);
		fprintf(memQ_result,"%d\n",Query);
		printf(" %d",i);
	}
	fclose(array);
	fclose(keys);
	fclose(memQ_result);
	return 0;
}

void append(char *str,int *array)
{
	int i=0,j=0;
	char str1[20];
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

void sort(int *b)
{
	int i,j,temp,pos;
	for (i=0;i<(length-1);i++)
	{	
		pos=i; 
		for(j=i+1;j<length;j++)
		{
			if ( *(b+pos)>*(b+j))
				pos=j;
		}
		if(pos!=i)
		{
			temp=*(b+i);
			*(b+i)=*(b+pos);
			*(b+pos)=temp;
		}
	}
}

int memQ(int *b,int key)
{
	int first,last,mid,Query;
	first=0;
	last=length-1;
	mid=(first+last)/2;
	while (first<=last) 
	{
		if (*(b+mid)<key)
			first = mid+1;    
		else if (*(b+mid)==key) 
		{
			Query=1;
			break;
		}
		else
			last=mid-1;
			mid=(first+last)/2;
	}
	if (first>last)
		Query=0;
	return Query;
}
