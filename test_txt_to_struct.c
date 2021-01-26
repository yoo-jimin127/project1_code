//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//	struct englishWord {
//		char word[16];
//		char meaning[10];
//	};
//
//int main (void) {
//
//	struct englishWord example[30];
//	int i = 0; 
//	FILE *f;
//	f = fopen("1.txt", "r");
//
//	for (i = 0; i < 30; i++) {
//		fscanf(f, "%s %s", &example[i].word, &example[i].meaning);
//	}
//
//	fclose(f);
//
//	for (i = 0; i < 30; i++) {
//		printf("%s %s\n", example[i].word, example[i].meaning);
//		}
//
//	return 0;
//}

 #include <stdio.h>

struct member{
	char name[10];
	int age;
	char sex[3];
	char city[10];
};



int main()
{
	struct member m[3];
	int i;
	FILE *f;

	f=fopen("a.txt","r");

	for(i=0;i<3;i++)
	fscanf(f,"%s %d %s %s",m[i].name,&m[i].age, m[i].sex, m[i].city);
	fclose(f);

	for(i=0;i<3;i++)
	printf("%s %d %s %s\n",m[i].name,m[i].age, m[i].sex, m[i].city);
	return 0;

}
