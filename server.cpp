#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include "usastring.h"
#include "request.h"
#include <cstring>
#include <iostream>
#include"utility.h"
#include "response.h"
using namespace std;
#include <arpa/inet.h> 
// Driver Code

#define PORT 8000
# define IP "192.168.178.173"

// int main()
// {
//     Response r;
//         cout<<get_file_path("a.html")<<endl;
//     r.set_body(get_file_path("23.jpg"));
//     r.print();
//     return 0;
// }

int main()
{
    int server_fd, new_socket; long valread;
    sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Only this line has been changed. Everything is same.
   // const char *hello = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 240\n\n<!DOCTYPE html><html><body><h1>My First Heading</h1><p>My first paragraph.</p></body></html>";
//const char *hello ="HTTP/1.1 200 OK\nContent-Length: 240\nConnection: Keep-Alive\nContent-Encoding: gzip\nContent-Type: text/plain; charset=\"utf-8\"\nDate: Fri Jan 14 11:35:01 2022\n\n<!DOCTYPE html><html><body><h1>My First Heading</h1><p>My first paragraph.</p></body></html>";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        cout<<"not created"<<endl;
        exit(EXIT_FAILURE);
    }
    

    address.sin_family = AF_INET;
    address.sin_addr.s_addr =inet_addr(IP);
    address.sin_port = htons( PORT );
    
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    
    
    if (bind(server_fd, (sockaddr *)&address, sizeof(address))<0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 100) < 0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        cout<<"http://{}:{}\n"x.format(IP,PORT);
        ("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            cout<<"In accept";
            exit(EXIT_FAILURE);
        }
        
        char buffer[30000] = {0};
        valread = read( new_socket , buffer, 30000); 
        Request request;
        request.parser(string(buffer));
        Response r(request);
        //request.print();
        r.send_response(new_socket);
         r.print();
         //write(new_socket , hello ,strlen(hello));
        close(new_socket);
    }
    return 0;
}