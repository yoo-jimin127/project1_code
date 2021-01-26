#include <stdio.h>
#include <stdlib.h>
#include <header.h>

void func() {
	char buf[BUFFER_SIZE];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("&d &s", &(node[i].age), node[i].name);
	}

	fflusk(stdin);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", node[i].age, node[i].name);
	} 

	if (fgets(buf, BUFFER_SIZE, stdin) == NULL) {
		fprintf(stderr, "fgets error\n");
		exit(1);
	}

	fputs(buf, stdout);

	exit(0);
}
