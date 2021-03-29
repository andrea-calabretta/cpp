#include <iostream>
#include <thread>

#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

const int PORT = 8080;


void process_connection(int new_socket){
	char buffer[1024] = {0};
	string hello = "Hello from server";
	int valread;

	valread = read(new_socket, buffer, 1024);
	cout << buffer << endl;

	this_thread::sleep_for(chrono::seconds(5));

	send(new_socket, hello.c_str(), hello.size(), 0);
	cout << "Hello message sent" << endl;

}

int main(int argc, char const *argv[])
{
	int server_fd, new_socket;
	struct sockaddr_in address;
	int addrlen = sizeof(address);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
 
	// 	creazione della socket
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	//	Bind porta 8080
	//::bind necessario in c++11 per evitare conflitto con bind definita in std
	if (::bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	// Coda richieste pending
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	//	Run forever
	while(true){
		//Accept
		if ((new_socket = accept(server_fd, (struct sockaddr *)& address, (socklen_t*)&addrlen))<0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		thread mc(process_connection, new_socket);
		mc.detach();
	}	
return 0;
}

