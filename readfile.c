#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);

    char buffer[2048];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));

    ssize_t bytes_written = write(1, buffer, bytes_read);

    close(fd);
}