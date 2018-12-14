#include <stdio.h>

int isEnter(char Character){
	if(Character=='\n')
		return 1;
	else 
		return 0;
}

int isSpecial(char Character){
	if((Character=='#') || (Character=='*'))
		return 1;
	else
		return 0;
}

void main(void)
{
	char name[26];
	int i, loopReturn = 1;
	do{
		printf("\nEnter your name. '*' and '#' should not be included.\n");
		printf("Name: ");
		fflush(stdin);
		for(i=0;i<25;i++)
		{
			scanf_s("%c", &name[i]);
			if(isSpecial(name[i])){
				printf("Special Character detected. Enter Again\n");
				break;
			}
			else if(isEnter(name[i])){
				loopReturn=0;
				break;
			}
		}
	}while(loopReturn==1);
	printf("Name entered is ");
	for(int j=0;j<i;j++)
		printf("%c", name[j]);
}