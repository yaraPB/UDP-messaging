#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
    printf("UDP Message Sender\n");
    
    
    // Send message to phone
    int socket_id = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Socket = %d\n", socket_id);
    
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(12345);
    sin.sin_addr.s_addr = inet_addr("192.168.100.21");
    
    
    for (int i=0; i<100; i++){
    const char* message = "Message from the computer";
    sendto(socket_id, message, strlen(message),0,
    (struct sockaddr *)&sin, sizeof(sin));
    }

}