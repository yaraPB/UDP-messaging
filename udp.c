#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 2048

int main(){
    printf("UDP Message Sender\n");
    
    
    // Send messages to phone
    int socket_id = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Socket = %d\n", socket_id);
    
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = inet_addr("192.168.100.16");

    struct sockaddr_in s_computer;
    s_computer.sin_family = AF_INET;
    s_computer.sin_port = htons(PORT);
    s_computer.sin_addr.s_addr = inet_addr("192.168.100.16");
    
        const char* message = "NEW NEW Message";
        sendto(socket_id, message, strlen(message),0, (struct sockaddr *)&sin, sizeof(sin));
    
    // Receive messages to phone
    unsigned char buf[BUFFER_SIZE]; // receive buffer

    int comp_id = socket(AF_INET, SOCK_DGRAM, 0);
    int res = bind(comp_id, (struct sockaddr *) &s_computer, sizeof(s_computer));
    
    printf("Waiting on Port %d\n", PORT);
    int recvlen = recvfrom(socket_id, buf, BUFFER_SIZE, 0, (struct sockaddr *)&s_computer, sizeof(s_computer));
    
    // check(recvlen, "Sorry, the recvfrom failed");

    printf("Message received = %s\n", buf);
}