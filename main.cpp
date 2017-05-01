#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = (char **) malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int main(void)
{
    int i;
    char *foo = "foo";
    char *bar = "bar";
    char str[80] = "";
    int id[50] = {12345542, 12345542, 1231579};
    int value[50] = {2,4,5};
    int num = 3;
    char data[50] = "";
    char bufferr[10];
    // SO SERVE PRA CONCATENAR UMA STRING ALEATORIA output = 12345542;2;12345542;4;1231579;5;
    sprintf(bufferr, "%d", 12345542);
    strcat(data, bufferr);
    strcat(bufferr, "");
    strcat(data, ";");
    sprintf(bufferr, "%d", value[0]);
    strcat(data, bufferr);
    strcat(bufferr, "");
    strcat(data, ";");
    for(i=1;i<+num; i ++){
        sprintf(bufferr, "%d", id[i]);
        strcat(data, bufferr);
        strcat(bufferr, "");
        strcat(data, ";");
        //sprintf(bufferr, "%d", i);
        sprintf(bufferr, "%d", value[i]);
        strcat(data, bufferr);
        strcat(data, ";");
        strcat(bufferr, "");
    }
    printf("%s\n",data);
    char teste[128];
    char *ptr;
    char **tokens;
    tokens = str_split(data, ';'); // FUNCAO QUE RETORNA char** COM A STRING SEPARADA POR  ; , mais ou menos uma funcao split

    if (tokens)
    {
        int e;
        for (e = 0; *(tokens + e); e++)
        {
            printf("data=[%s]\n", *(tokens + e));

            sprintf(bufferr, "%d", 12345542); // transformo o numero numa string
            if(*(tokens + e) == bufferr){ // comparo com a posicao  AQUI ESTA DANDO ERRO
                printf("Acende o led\n");
            }

        }
        printf("\n");
    }
}
