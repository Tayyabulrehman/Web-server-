#ifndef Response_H // include guard
// #include
#define Response_H
#include"usastring.h"
#include"utility.h"
#include<string>
#include <unistd.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include <sys/socket.h>
// std::string body ="200 OK
// Access-Control-Allow-Origin: *
// Connection: Keep-Alive
// Content-Encoding: gzip
// Content-Type: text/html; charset=utf-8
// Date: Mon, 18 Jul 2016 16:06:00 GMT
// Etag: "c561c68d0ba92bbeb8b0f612a9199f722e3a621a"
// Keep-Alive: timeout=5, max=997
// Last-Modified: Mon, 18 Jul 2016 02:36:04 GMT
// Server: Apache
// Set-Cookie: mykey=myvalue; expires=Mon, 17-Jul-2017 16:06:00 GMT; Max-Age=31449600; Path=/; secure
// Transfer-Encoding: chunked
// Vary: Cookie, Accept-Encoding
// X-Backend-Server: developer2.webapp.scl3.mozilla.com
// X-Cache-Info: not cacheable; meta data too large
// X-kuma-revision: 1085259
// x-frame-options: DENY";


class Response
{
   int  status;
   std::string msg;
   std::string content_type;
   std::string encoding;
   std::string date;
   std::string server;
   usa::string header;
    char* body;
   int content_length;

public:

Response(Request&r)
{
   auto uri=r.get_url();
   cout<<uri<<endl;
   if(uri.size()>1)
   {

   auto  file_path=get_file_path(uri);
   if (file_path != "")
   {
      cout<<file_path<<endl;
      status=200;
      this->msg="OK";
      set_content_type(usa::string(uri).split('.')[1]);
      set_body(file_path);
      set_header();
   }
   else
   {
      cout<<"erro2"<<endl;
       status=404;
      this->msg="Not Found";
   }
   }
else{
     cout<<"erro2"<<endl;
   status=404;
      this->msg="Not Found";
}

// set_header();
// set_body("r");
}

void set_content_type(std::string file_extention)
{
   if(file_extention == ".html")
   content_type="text/html";

   else if (file_extention==".js")
   content_type="text/js";

   else if (file_extention==".css")
   content_type="text/css";
   
   else if (file_extention==".png")
   content_type="image/png";

   else if (file_extention==".jpeg")
   content_type="image/jpeg";
   
   else if(file_extention==".gif")
   content_type="image/gif";
}

void set_header()
{
   header="HTTP/1.1 {} {}\n"x.format(status,this->msg);
   header+="Access-Control-Allow-Origin: *\n";
   header+="Content-Length: {}\n"x.format(this->content_length);
   header+= "Connection: Keep-Alive\n";
  // header+= "Content-Encoding: inflate\n";
  header+= "Content-Type: text/html\n";
  header+= "Date: {}\n"x.format(get_local_time());
header+="\n";
}

void set_body(std::string file_dir)
{
   ifstream file;
   if ((usa::string(content_type).split('/')[0])=="text")
   file=ifstream(file_dir, ios::in|ios::ate);


  if (file.is_open())
  {
    int size = file.tellg();
    content_length=size;
    body = new char [size];
    file.seekg (0, ios::beg);
    file.read (body, size);
    file.close();
  }
  else
  {
     cout<<"File does not exist"<<endl;
  }

}

void  send_response(int file_discripter)
{
  
std:: string response=string(header)+body;

if(write(file_discripter,response.c_str(), response.size())<0)
{
   std::cout<<"in witing";
}

}
void print()
{
   std::cout<<body<<endl;
}

};

#endif