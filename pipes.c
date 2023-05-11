#include <stdio.h>
#include <unistd.h>


//Using Pipes in inter-process communincation
int main() {
    int pid;
    int pipe1[2];
    int pipe2[2];
    char msg1[500], msg2[500];
    char msgRead[500];
    int pipe1Status, pipe2Status;

    printf("Please enter data to share to the second Process from the first: ");
    scanf("%499s", msg1);

    printf("Please enter data to share to the first Process from the second: ");
    scanf("%499s", msg2);

    pipe1Status = pipe(pipe1);
    pipe1Status = pipe(pipe2);

    if(pipe1Status == -1 || pipe2Status == -1){
        printf("Please re-enter the input!\n");
        return 1;
    }

    pid = fork();
    
    if(pid != 0) {
        close(pipe1[0]);
        close(pipe2[1]);

        printf("Currently in the parent process: Writing data to pipe 1: %s\n", msg1);
        write(pipe1[1], msg1, sizeof(msg1));
        write(pipe2[0], msgRead, sizeof(msgRead));
    } 
    else {
        close(pipe1[1]);
        close(pipe2[0]);
        read(pipe1[0], msgRead, sizeof(msgRead));
        printf("Currently in the child process: Reading data from pipe 1: %s\n", msgRead);
        printf("Currently in the child process: Writing data to pipe 2: %s\n", msg2);
        write(pipe2[1], msg2, sizeof(msg2));
    }
    return 0;
}