#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    char buffer[2048];
    ssize_t bytes_read;

    if (argc == 1) {
        fd = 0;
    } else {
        for (int i = 1; i < argc; i++) {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1) {
                perror("open");
                continue;
            }

            while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
                ssize_t bytes_written = write(1, buffer, bytes_read);
                if (bytes_written == -1) {
                    perror("write");
                    close(fd);
                    return 1;
                }
            }
            if (bytes_read == -1) {
                perror("read");
            }
            close(fd);
        }
    }
    if (fd == 0) {
        while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
            ssize_t bytes_written = write(1, buffer, bytes_read);
            if (bytes_written == -1) {
                perror("write");
                return 1;
            }
        }
        if (bytes_read == -1) {
            perror("read");
        }
    }
    return 0;
}