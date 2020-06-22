#define _GNU_SOURCE
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>
#include <stdlib.h>

#define PORT 8080
#define NUMBER_OF_CHALLENGES 11

int main(int argc, char const *argv[])  { 
    int sock = 0, i; 
    struct sockaddr_in serv_addr; 
    char * answers [NUMBER_OF_CHALLENGES] = {"entendido\n", "0854780\n", "martin luther king\n", "es_go_lo_dro_bo\n", "too_easy\n", ".RUN_ME\n", 
                    "in_de_ter_mi_na_do\n", "thunder thunder thunder thundercats\n", "this is awesome\n", "chin_chu_lan_cha\n", "gdb_manda\n"};
    
    setvbuf(stdout, NULL, _IONBF, 0);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
    
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "0.0.0.0", &serv_addr.sin_addr) <= 0) {
        perror("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("\nConnection Failed \n");             
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < NUMBER_OF_CHALLENGES; i++) {
        printf("Press ENTER to send the challenge %d's correct answer\n", i);  
        while (getchar() != '\n');
        send(sock , answers[i], strlen(answers[i]), 0 );
    }

    printf("Finished! All challenges solved successfuly\n");
    return 0; 
} 
