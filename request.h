#ifndef Request_H // include guard
// #include
#define Request_H
#include"usastring.h"
#include<string>
#include<iostream>
class Request
{
   using str = usa::string;
 str type;
 str uri;
 vector<string> accept;
 str host;
 vector<string> encoding;
    
public:
    Request()
    {
    type=uri=host="";
    }
    void parser(str buffer)
    {
        auto request_header = buffer.splitlines();    // convert request buffer to vector of string
        auto first_line = str(request_header[0]).split(); // read first lines from string vector
        this->type = first_line[0];     // from first line of rquest get type of request 
        this->uri =first_line[1];       // get url from first line request


        this->host = str(request_header[1]).split()[1];  // get host from second line of request 
        // auto third_line =str(request_header[5]).split(':')[1];  /// 
        // this->accept=str(third_line).split(',');
        // this-> encoding =str(request_header[5]).split(':');

    }
   string get_url()
    {
        return string(this->uri);
    }
     string get_host()
    {return string(this->host); }
    vector<string> get_accept()
    {return this->accept;}
    void print()
    {
        std:: cout<<"Type:"<<type<<endl;
       std:: cout<<"URL:"<<uri<<endl;
        std:: cout<<"Host:"<<host<<endl;
         std:: cout<<"Accept:";
        for( auto x:accept)
        std::cout<<x<<",";

        std::cout<<endl;

        std:: cout<<"Encoding:";
        for(auto x:encoding)
        std::cout<<x<<",";
        cout<<endl;   
    }

};



#endif