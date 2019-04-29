#include "irc_udp.h"

t_ui    *ui_alloc(char * pseudo) {
    t_ui    *ui;    
    
    if ((ui = (t_ui *)malloc(sizeof(t_ui))) == NULL)
        return (NULL);
    ui->pseudo = pseudo;
    ui->li_messages = lst_alloc(free, NULL);
    ui_init_line(ui);
    memset(ui->buffer_in, 0, sizeof(ui->buffer_in) / sizeof(ui->buffer_in[0]));
    return (ui);
}

void    ui_free(t_ui * ui) {
    lst_free(ui->li_messages);
    free(ui->pseudo);
    free(ui);
}

void    ui_init_line(t_ui * ui) {
    ui->len = 0;
    memset(ui->line, 0, sizeof(ui->line) / sizeof(ui->line[0]));
}

void    ui_treat_buffer(t_ui * ui) {
    char    *tmp;

    while ((tmp = strchr(ui->buffer_in, '\n')) != NULL) {
        size_t s = tmp - ui->buffer_in;
        size_t len = strlen(ui->buffer_in);
        lst_add(ui->li_messages, strndup(ui->buffer_in, s));
        memmove(ui->buffer_in, ui->buffer_in + s + 1, len - s);
        memset(ui->buffer_in + len - s, 0, s);
    }
}