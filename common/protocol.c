#include "protocol.h"

position_t *init_position()
{
    position_t *p = (position_t *)malloc(sizeof(position_t));
    if (p == NULL)
    {
        perror("malloc position");
        exit(EXIT_FAILURE);
    }
    p->position_x = -1;
    p->position_y = -1;
    return p;
}

void *free_position(position_t *p)
{
    free(p);
}

message_t *init_message()
{
    message_t *m = (message_t *)malloc(sizeof(message_t));
    if (m == NULL)
    {
        perror("malloc message");
        exit(EXIT_FAILURE);
    }
    m->msg_type = -1;
    m->ch = 'q';
    m->direction = 0;
}

message_t *create_message(int msg_type, char ch, direction_t direction)
{
    message_t *m = init_message();
    m->msg_type = msg_type;
    m->ch = ch;
    m->direction = direction;
    return m;
}

//free message
void *free_message(message_t *m)
{
    free(m);
}