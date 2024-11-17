#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    struct sockaddr_in serv_addr;
    char *message = "Client: Hello Server!";
    char buffer[BUFFER_SIZE] = {0};

    // Création du socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convertir l'adresse IP en format réseau
    if (inet_pton(AF_INET, "34.75.151.117", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connexion au serveur
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    send(sock, message, strlen(message), 0);
    printf("Message sent\n");

    int valread = read(sock, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    close(sock);
    return 0;
}
