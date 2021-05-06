#include "get_next_line.h"

int    strlen_eol(char *s)
{
    int length;

    length = 0;
    while (s && s[length] && s[length] != '\n')
        length++;
    return (length);
}

char *strjoin_to_eol(char *line, char *buffer)
{
    char *new_line;
    int i;
    int j;

    if (!(new_line = malloc(strlen_eol(line) + strlen_eol(buffer) + 1)))
        return (NULL);
    i = 0;
    while (line[i] != 0 && line)
    {
        new_line[i] = line[i];
        i++;
    }
    j = i;
    i = 0;
    while (buffer && buffer[i] != 0 && buffer[i] != '\n')
    {
        new_line[i + j] = buffer[i];
    }
    new_line[i + j] = '\0';
    free(line);
    return (new_line);
}
//char    *strjoin_to_eol(char *s1, char *buf)
//{
//    char    *tab;
//    int        i;
//    int        j;
//
//    i = 0;
//    j = 0;
//    if (!(tab = malloc(strlen_eol(s1) + strlen_eol(buf) + 1)))
//        return (NULL);
//    while (s1 && s1[j])
//        tab[i++] = s1[j++];
//    while (buf && *buf && *buf != '\n')
//        tab[i++] = *buf++;
//    tab[i] = 0;
//    free(s1);
//    return (tab);
//}
int strchr_pos(char *line, char c)
{
    int pos;

    pos = 0;
    while (line[pos] && line[pos] != c)
    {
        pos++;
    }
    if (line[pos] != c)
    {
        return (-1);
    }
    return (pos);
}

void ft_bzero(char *s, int size)
{
    int i;
    i = 0;
    while (i < size)
    {
        s[i] = 0;
        i++;
    }
}


//int get_next_line(char **line)
//{
//    static char    buffer[BUFFER_SIZE + 1];
//    int ret;
//
//    if (!line) //si la ligne est vide, on y colle le buffer
//    {
//        if (!(*line = strjoin_to_eol(NULL, buffer)))
//            return (-1);
//    }
//    ret = 1;
//    while (strchr_pos(*line, '\n') == -1 && ret && ret != -1)
//    {
//        ft_bzero(buffer, BUFFER_SIZE + 1);
//        ret = read(0, buffer, BUFFER_SIZE);
//        if (!(*line = strjoin_to_eol(*line, buffer)))
//            return (-1);
//    }
//    int i = 0;
//    ret = strchr_pos(buffer, '\n') + 1;
//    if (buffer[0] == 0)
//        return (0);
//    while (buffer[ret] != '\0' && ret)
//    {
//        buffer[i] = buffer[ret];
//        i++;
//        ret++;
//    }
//    buffer[i] = 0;
//    return (1);
//}
int        get_next_line(char **line)
{
    static char        buf[BUFFER_SIZE + 1];
    int                ret;
    int                i;
    
    if (!line || !(*line = strjoin_to_eol(NULL, buf)))
        return (-1);
    ret = 1;
    while (strchr_pos(buf, '\n') == -1 && ret && ret != -1)
    {
        ft_bzero(buf, BUFFER_SIZE + 1);
        ret = read(0, buf, BUFFER_SIZE);
        if (!(*line = strjoin_to_eol(*line, buf)))
            return (-1);
    }
    i = 0;
    ret = strchr_pos(buf, '\n') + 1;
    if (buf[0] == 0)
        return (0);
    while (buf[ret] != '\0' && ret)
        buf[i++] = buf[ret++];
    buf[i] = 0;
    return (1);
}
