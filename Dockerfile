# Utiliser une image de base Ubuntu
FROM ubuntu:20.04

# Installer les dépendances nécessaires (par exemple, gcc pour compiler C)
RUN apt-get update && apt-get install -y \
    build-essential \
    && apt-get clean

# Copier votre code source dans le conteneur
COPY . /app

# Spécifiez le répertoire de travail
WORKDIR /app

# Compiler le code C
RUN gcc -o server server.c

# Exposer le port sur lequel le serveur va écouter (par exemple, 8080)
EXPOSE 8080

# Lancer le serveur
CMD ["./server"]
