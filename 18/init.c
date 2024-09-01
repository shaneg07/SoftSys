#include "record_struct.c"
#include <fcntl.h>
#include <unistd.h>

int main() {
    Record r[] = {
        {.data = "Shane"},
        {.data = "Gomes"},
        {.data = "IIITB"},
        {.data = "Record new"},
    };

    int fd = open("records", O_CREAT | O_EXCL | O_RDWR, 0644);

    write(fd, r, sizeof(r));

    return 0;
}