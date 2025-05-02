#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#define DWL "/usr/local/bin/dwl"
#define SL  "/usr/local/bin/slstatus-rs"

int main() {
    int status;
    int coms[2];
    status = pipe(coms);
    assert(status != -1);

    if (fork() == 0) {
        status = close(coms[0]);
        assert(status != -1);
        status = dup2(coms[1], 1);
        assert(status != -1);
       
        execl(SL, SL, "-s", NULL);
        fprintf(stderr, "slstatus-rs execve failed!\n");
        exit(-1);
    } 
    
    status = close(coms[1]);
    assert(status != -1);
    status = dup2(coms[0], 0);
    assert(status != -1);

    execl(DWL, DWL, NULL);

    fprintf(stderr, "dwl execve failed!\n");
    return -2;
}
