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

    off_t text_size = lseek(input_fd, 0, SEEK_END);
    char buf[text_size];
    int a;

    for (int i = 0; i <= text_size; i++) {
        lseek(input_fd, i, 0);
        read(input_fd, &a, 1);
        if (isalpha(a)) {
            a = toupper(a);
        }

        buf[i] = (char) a;
    }

    write(output_fd, buf, text_size);

    close(input_fd);
    close(output_fd);
    return 0;
}
