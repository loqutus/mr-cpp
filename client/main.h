#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H
#include "../lib/tcpclient/tcpclient.h"
#include "../lib/optparse/optparse.h"
#include "../lib/read_file/read_file.h"
#include "../lib/json/json.h"
#include <chrono>
#include <thread>
int main(int argc, char** argv);
int send_to_server(std::unordered_map<std::string, std::string> json_map, std::string kind, std::string host, std::string port);
std::string add_action(std::string action, std::string kind, std::string data);
#endif //PROJECT_MAIN_H
