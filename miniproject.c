#include<stdio.h>
#include<conio.h>

struct medicine{
	char name[100];
	int quantity;
	int price;
	int exp;
	int mfg;
};
struct data{
	struct medicine medicines[100];	
}d;

void openFile();
void startWork();
void orders();
void saveFile();
void input(int i);
void newMed();
void printMeds();
void updateMed();
int countMeds();
void delMed();
void searchMedicine();
void medicineDetails(int i);

int main()
{
	openFile();
	startWork();
	getch();	
}
void startWork()
{
	int c;
	orders();
    printf("\nselect Any one option from above\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1: 
			printMeds();
			break;
		case 2:
			newMed();
			break;
		case 3:
			printMeds();	
			updateMed();
			break;
		case 4:
			printMeds();
			delMed();
			break;
		case 5:
			searchMedicine();
			break;
		default: printf("\nError!!\nEnter a Digit between 1 to 4.");
		break;
	}
	startWork();
}
void newMed()
{
	int i=countMeds();
	input(i);	
}
void delMed()
{
	int i;
	printf("\nEnter the S.No\n");
	scanf("%d",&i);
	for(i-=1;i<countMeds();i++){
		d.medicines[i] = d.medicines[i+1];
	}
	saveFile();
}
void searchMedicine()
{
	int i;
	printf("\nEnter S.No\n");
	scanf("%d",&i);
	if(d.medicines[i-1].name[0] != '\0')
	{
		printf("\n\nS.No \tName \tQuantity \tPrice  \tMfg  \tExp");
		printf("\n--------------------------------------------------");
		medicineDetails(i-1);	
		printf("\n\n");
	}
	else
		printf("\nMedicine Not Found!!!");
}
int countMeds()
{
	int i=0;
	for(i;i<100;i++)
	{
		if(d.medicines[i].name[0]=='\0')
			return i;
	}
}
void updateMed()
{
	int i;
	printf("\nEnter S.no of the Medicine\n");
	scanf("%d",&i);
	input(i-1);
}
void input(int i)
{
	printf("\nMedicine Name\t");
	scanf("%s",&d.medicines[i].name);
	printf("\nQuantity\t");
	scanf("%d",&d.medicines[i].quantity);
	printf("\nPrice/Piece\t");
	scanf("%d",&d.medicines[i].price);
	printf("\nMfg Year\t");
	scanf("%d",&d.medicines[i].mfg);
	printf("\nExp Year\t");
	scanf("%d",&d.medicines[i].exp);
	saveFile();
}

void saveFile()
{
	FILE *fPtr;
	fPtr=fopen("medicines.txt","w");
	fwrite(&d,sizeof(d),1,fPtr);
	fclose(fPtr);
}

void openFile()
{
	FILE *fPtr;
	fPtr = fopen("medicines.txt","r");
    fread(&d,sizeof(d),1,fPtr);
	fclose(fPtr);
}

void printMeds()
{
	int i=0;
	printf("\n\nS.No \tName \tQuantity \tPrice \tMfg \tExp");
	printf("\n--------------------------------------------------");
    for(i=0;i<countMeds();i++){
		if(d.medicines[i].name[0]!='\0'){
			medicineDetails(i);
		}else
		{
			break;
		}
	}
	printf("\n\n");
}
void medicineDetails(int i)
{
			printf("\n%d \t%s \t %d \tRs.%d/- \t %d \t %d",i+1,d.medicines[i].name,d.medicines[i].quantity,d.medicines[i].price,d.medicines[i].mfg,d.medicines[i].exp);	
}
void orders()
{
	printf("\n1.Print Medicine Details");
	printf("\n2.Insert New Medicine Detail");
	printf("\n3.Update Medicine Details");
	printf("\n4.Delete Medicine Detail");
	printf("\n5.Search Medicine");
}
