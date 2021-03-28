#include <iostream>

#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int PORT = 8080;

using namespace std;

int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	string hello = "Hello from server";

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

//		Creazione della socket
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

//		Bind porta 8080
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

//		Code richieste pending
	if (listen(server_fd, 3) < 0)
	{	
		perror("listen");
		exit(EXIT_FAILURE);
	}

//		Accept
	if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	valread = read(new_socket, buffer, 1024);
	cout << buffer << " " << valread << endl;
	send(new_socket, hello.c_str(), hello.size(), 0);
	cout << "Hello message sent" << endl;
	return 0;
}
