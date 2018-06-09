#include <iostream>
#include <fcntl.h>
#include <zconf.h>

int main(int argc, char *argv[]) {
    int input_fd = open(argv[1], O_RDONLY);
    int output_fd = open(argv[2], O_RDWR);
    if( input_fd == -1 or output_fd == -1)
    {
        perror("Open Failed");
        return 1;
    }

    long text_size = lseek(input_fd, 0, SEEK_END);
    std::string result = "";
    int a;

    for (long i = 0; i < text_size; i++) {
        lseek(input_fd, i, 0);
        read(input_fd, &a, 1);
        if (isalpha(a)) {
            result += toupper(a);
        } else {
            result += (char) a;
        }
    }

    write(output_fd, result.c_str(), text_size);

    close(input_fd);
    close(output_fd);
    return 0;
}
