#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H
#include "../lib/tcpclient/tcpclient.h"
#include "../lib/optparse/optparse.h"
#include "../lib/read_file/read_file.h"
#include "../lib/json/json.h"
#include <chrono>
#include <thread>
int main(int argc, char** argv);
int send_to_server(std::string name, std::string type, std::string filename, std::string host, std::string port);
#endif //PROJECT_MAIN_H
