#include "irc_udp.h"

static int ui_stdin_custom_run(int fd_get, int fd_stop) {
    char    c;

    while (1) {
        read(0, &c, sizeof(c));
        write(fd_get, &c, sizeof(c));
        read(fd_stop, &c, sizeof(c));
        if (c == 1)
            return (0);
    }
    return (1);
}

int     ui_getstdin_custom(int fd_get) {
    char     c;

    if (read(fd_get, &c, sizeof(c)) == -1)
        return (ERR);
    return (c);
}

void    ui_getstdin_stop(int fd_stop) {
    char c;

    c = 1;
    write(fd_stop, &c, sizeof(c));
}

void    ui_getstdin_continue(int fd_stop) {
    char c;

    c = 0;
    write(fd_stop, &c, sizeof(c));
}

t_bool  ui_stdin_custom_setup(int * fd_get, int * fd_stop) {
    int fd_getp[2];
    int fd_stopp[2];
    pid_t pid_child;

    if (pipe2(fd_getp, O_NONBLOCK) == -1)
        return (FALSE);
    else if (pipe(fd_stopp) == -1) {
        close(fd_getp[0]);
        close(fd_getp[1]);
        return (FALSE);
    }

    pid_child = fork();
    if (pid_child == -1) {
        close(fd_getp[0]);
        close(fd_getp[1]);
        close(fd_stopp[0]);
        close(fd_stopp[1]);
        return (FALSE);
    }
    

    if (pid_child == 0) {
        close(fd_getp[0]);
        close(fd_stopp[1]);

        int ret = ui_stdin_custom_run(fd_getp[1], fd_stopp[0]);

        close(fd_getp[1]);
        close(fd_stopp[0]);
        exit(ret);
    }
    else {
        close(fd_getp[1]);
        close(fd_stopp[0]);

        *fd_get = fd_getp[0];
        *fd_stop = fd_stopp[1];
    }
    return (TRUE);
}