#include <stdio.h>
#include <sys/socket.h>
#include <string.h>

int main(){
    printf("UDP Message Sender\n");

    const char* message = "Hello";
    
    // number of characters 
    int size_char = sizeof(message)/sizeof(message[0]);

    // Send message to phone
    sendto(int socket, message, sizeof(char*)*strlen(message),0,
    const struct sockaddr *address, size_t address_len);
}