#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __sgi
#include <sys/fstyp.h>
#include <sys/fsid.h>
#endif

void die(char *msg) {
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

void usage() {
	fprintf(stderr, "Usage:\tfsreveal\n");
	fprintf(stderr, "\tfsreveal -h\n");
}

void help() {
	fprintf(stderr, "fsreveal: show filesystem types known to the kernel\n");
	usage();
}

int main (int argc, char *argv[])
{
	char buf[FSTYPSZ+1] = {0};
	int rc, i;

	if (argc >= 2) {
		if (!strcmp(argv[1], "-h")) {
			help();
		} else {
			usage();
		}
		return EXIT_FAILURE;
	}

	rc = sysfs(GETNFSTYP);

	if (rc < 0) {
		die("sysfs(GETNFSTYP) returned bogus number of types");
	}

	for (i = 0; i < rc; i++) {
		sysfs(GETFSTYP, i, buf);
		printf("%0d\t%s\n", i, buf);
	}

	return EXIT_SUCCESS;
}

