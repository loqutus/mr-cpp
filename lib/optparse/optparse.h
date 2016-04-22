//
// Created by Ruslan Gustomyasov on 05/01/16.
//

#ifndef PROJECT_OPTPARSE_H
#define PROJECT_OPTPARSE_H
#include <boost/program_options.hpp>
#include <string>

class optparse {
public:
    optparse(int argc, char **argv);
    std::string get(std::string optname);
private:
    boost::program_options::options_description desc;
    boost::program_options::variables_map vm;
};


#endif //PROJECT_OPTPARSE_H
