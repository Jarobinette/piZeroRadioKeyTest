#include <fcntl.h>
#include <unistd.h>

#include <iostream>
#include <cerrno>
#include <cstring>

int main(int argc, char **argv)
{
    const char *device = (argc > 1) ? argv[1] : "/dev/ttyUSB0";

    int fd = open(device, O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd < 0)
    {
        std::cerr << "Cannot open " << device << ":" << std::strerror(errno) << "\n";
        return 1;
    }
    std::cout << "Opend : " << device << "\n";
    close(fd);

    return 0;
}