#include <stdio.h>

struct mem {
	char name[10];
	int age;
	char sex[3];
	char city[10];
};

int main() {
	struct mem m[3];
	int i;
	FILE* f;
	f = fopen("1.per", "r");

	for (i = 0; i < 3; i++) {
		fscanf(f, "%s %d %s %s", &m[i].name, &m[i].age, &m[i].sex, &m[i].city);
	}

	fclose(f);

	for (i = 0; i < 3; i++) {
		printf("%s %d %s %s\n", m[i].name, m[i].age, m[i].sex, m[i].city);
	}

	return 0;
}
