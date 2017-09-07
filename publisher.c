#include <stdio.h>
#include <string.h>
#include "holymsg.h"

#define DEBUG(fmt, args...) printf("P: " fmt "\n", ##args)

int main()
{
    int i = 3, j = 5;
    char *s;

    s = "test";
	holymsg_publish("echo", s, strlen(s) + 1);
    
    s = "baby";
	holymsg_publish("hello", s, strlen(s) + 1);
    
	holymsg_publish("plus", &i, sizeof(i));
	holymsg_publish("plus", &j, sizeof(j));

	holymsg_publish("minus", &i, sizeof(i));
	holymsg_publish("minus", &j, sizeof(j));

    return 0;
}

