#include <libgen.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    char *dirc, *basec, *bname, *dname;
    char *path = "/etc/passwd";
    basec = strdup(path);
    bname = basename(basec);

    printf("basename=%s\n",bname);
    return 0;
}
