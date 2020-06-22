#define _POSIX_SOURCE
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h>
#include <sys/socket.h> 
#include <unistd.h>
#include <time.h>
#include "myServer.h"
#include <signal.h>

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr
#define ECHO_COMMAND "echo -n "
#define MD5_COMMAND " | md5sum"
#define CHALLENGE_4_WRITE "La respuesta es es_go_lo_dro_bo\n"
#define CHALLENGE_5_SOLUTION "too_easy"
#define CHALLENGE_10_COMMAND_1 "gcc quine.c -o quine"
#define CHALLENGE_10_COMMAND_2 "./quine | diff - quine.c"
#define CHECK_ERROR(error, message) if(error < 0){ perror(message); exit(EXIT_FAILURE);}
#define CHECK_ERROR_NULL(error, message) if(error == NULL){ perror(message); exit(EXIT_FAILURE);}

// Prototypes
static void read_challenges(int sockfd);
static void challenge4();
static void challenge7();
static void challenge10();
static void challenge11();

static int ret;
static char answer [] __attribute__ ((section (".RUN_ME"))) = "respuesta";

int main() { 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
    socklen_t len = sizeof(cli);

    setvbuf(stdout, NULL, _IONBF, 0);
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    CHECK_ERROR(sockfd, "socket");
    
    memset(&servaddr, 0, sizeof(servaddr));
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    ret = bind(sockfd, (SA*)&servaddr, sizeof(servaddr));
    CHECK_ERROR(ret, "bind");
  
    // Now server is ready to listen and verification 
    ret = listen(sockfd, 5);
    CHECK_ERROR(ret, "listen");
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    CHECK_ERROR(connfd, "accept");
  
    // Function for chatting between client and server 
    read_challenges(connfd); 
  
    // After chatting close the socket 
    ret = close(sockfd);

    return 0;
}
  
// Function designed for chat between client and server. 
static void read_challenges(int sockfd) {
    char * buff = NULL;
    size_t len = 0;
    int size;

    FILE * client = fdopen(sockfd, "w+");
    CHECK_ERROR_NULL(client, "fdopen");
    FILE * command_file;
    char returning_hash[50] = {'\0'};

    printf("\033[1;1H\033[2J");

    for (int i = 0; i < NUMBER_OF_CHALLENGES; i++) {
        
        printf("------------- DESAFIO -------------\n");
        printf("%s\n", hints[i]);
        
        switch(i){
            case 3:
                challenge4();
                break;
            case 6:
                challenge7();
                break;
            case 9:
                challenge10();
                break;
            case 10:
                challenge11();
                break;
        }
        
        printf("\n\n----- PREGUNTA PARA INVESTIGAR -----\n");
        printf("%s\n\n", questions[i]);

        size = getline(&buff, &len, client);
        CHECK_ERROR(size, "getline");
        buff[size - 1] = '\0';
        char command[100] = ECHO_COMMAND;
        strcat(command, buff);
        strcat(command, MD5_COMMAND);
        command_file = popen(command, "r");
        CHECK_ERROR_NULL(command_file, "popen");
        CHECK_ERROR_NULL( fgets(returning_hash, 33, command_file), "fgets");

        ret = pclose(command_file);
        CHECK_ERROR(ret, "pclose");

        if(strcmp(returning_hash, answers[i]) != 0) {
            i--;
            printf("Respuesta incorrecta: %s", buff);
            sleep(2);
        }
            
        printf("\033[1;1H\033[2J");
    }

    printf("FELICITACIONES\n");
}

static void challenge4(){
    ret = write(13, CHALLENGE_4_WRITE, sizeof(CHALLENGE_4_WRITE));
    if(ret == -1)
        perror("write");
}

static void challenge7() {
    srand(time(NULL));

    int i, j = 0;
    char ans [] = "in_de_ter_mi_na_do\n";
    char aux [] = "0";

    for (i = 0; i < 200; i++) {
        if(i % 10 == 0) {
            aux[0] = ans[j++];
            ret = write(STDOUT_FILENO, aux, sizeof(aux));
            CHECK_ERROR(ret, "WRITE TO STDOUT");
        } else {
            aux[0] = rand() % 95 + 32;
            ret = write(STDERR_FILENO, aux, sizeof(aux));
            CHECK_ERROR(ret, "WRITE TO STDERR");
        }
    }
}

static void challenge10() {
    ret = 1;

    while(ret != 0) {
        ret = system(CHALLENGE_10_COMMAND_1);
        if(ret != 0) {
            printf("ENTER para reintentar\n");
            while (getchar() != '\n');
            printf("\033[1;1H\033[2J");
        } else {
            printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");
            ret = system(CHALLENGE_10_COMMAND_2);
            if(ret != 0) {
                printf("Diff encontro diferencias.\nENTER para reintentar\n");
                while (getchar() != '\n');
                printf("\033[1;1H\033[2J");
            }
        }
    }

    puts("La respuesta es chin_chu_lan_cha\n");
}

void gdbme() {
    int aux = 0;
    if(aux != 0x12345678)
        printf("ENTER para reintentar\n");
    else
        printf("La respuesta es gdb_manda\n");
}

void challenge11() {
    gdbme();
}