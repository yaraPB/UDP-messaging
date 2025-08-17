#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345
#define PORT_COMP 54321
#define BUFFER_SIZE 2048

int main(){
    printf("UDP Message Sender\n");
    
    
    // Send messages to phone
    int socket_id = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Socket = %d\n", socket_id);
    
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = inet_addr("192.168.100.21");

    struct sockaddr_in s_computer;
    s_computer.sin_family = AF_INET;
    s_computer.sin_port = htons(PORT_COMP);
    s_computer.sin_addr.s_addr = inet_addr("192.168.100.16");
    
    
    for (int i=0; i<100; i++){
    const char* message = "Message from the computer";
    sendto(socket_id, message, strlen(message),0,
    (struct sockaddr *)&sin, sizeof(sin));
    }


    unsigned char buf[BUFFER_SIZE]; // receive buffer

    // Receive messages to phone
    while(1){
        printf("Waiting on Port %d\n", PORT);
        int recvlen = recvfrom(socket_id, buf, BUFFER_SIZE, 0, (struct sockaddr *)&s_computer, sizeof(s_computer));
        
        if (recvlen>0){
            buf[recvlen] = 0;
            printf("Received message: \"%s\"\n", buf);
        }
    }
}