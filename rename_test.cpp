#include <cstring>
#include <iostream>
#include <sstream>

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " /path/to/temp/dir" << std::endl;
        return -1;
    }

    std::string temp_dir_str(argv[1]);
    temp_dir_str = temp_dir_str + "/XXXXXX";

    char * temp_filename = strdup(temp_dir_str.c_str());
    auto fd = mkstemp(temp_filename);
    if (fd == -1) {
        std::cerr << "Error generating temp file: " << std::strerror(errno) << std::endl;\
        return -1;
    }

    std::cout << "Generated temporary file: " << temp_filename << std::endl;
    std::stringstream ss;
    ss << temp_filename << ".moved";
    std::string renamed_temp_filename = ss.str();

    auto rename_res = ::rename(temp_filename, renamed_temp_filename.c_str());
    if (rename_res == -1) {
        std::cerr << "Error renaming file from: " << temp_filename << " to: " << renamed_temp_filename << std::endl;
        return -1;
    }

    std::cout << "Successfully renamed file from: " << temp_filename << " to " << renamed_temp_filename << std::endl;

    free(temp_filename);
    return 0;
}
