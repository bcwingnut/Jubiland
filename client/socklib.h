#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <strings.h>
#include <stdlib.h>
#include <pthread.h>
#include "request.pb-c.h"
#include "response.pb-c.h"

#define HOST_NAME "localhost"
#define PORT_NUM 8888
#define MAX_MSG_SIZE 65536
#define BUFF_SIZE 4096

int connect_to_server(char *host, int port);

Response *get_response(int fd);

int send_request(int sock, Request req);

pthread_mutex_t sock_write_lock;

#endif //CLIENT_SOCKET_H
