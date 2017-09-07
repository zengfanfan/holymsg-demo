#include <stdio.h>
#include <string.h>
#include "holymsg.h"

#define DEBUG(fmt, args...) printf("G: " fmt "\n", ##args)

static void echo(char *type, void *data, unsigned len)
{
    DEBUG("[%s] %s", type, data);
}

static void hello(char *type, void *data, unsigned len)
{
    DEBUG("[%s] %s", type, data);
}

static void plus(char *type, void *data, unsigned len)
{
    static int a = 0;
    int b = *(int *)data;
    DEBUG("%d [%s] %d = %d", a, type, b, a + b);
    a += b;
}

static void minus(char *type, void *data, unsigned len)
{
    static int a = 0;
    int b = *(int *)data;
    DEBUG("%d [%s] %d = %d", a, type, b, a - b);
    a -= b;
}

int main()
{
	holymsg_subscribe("echo", echo);
	holymsg_subscribe("hello", hello);
	holymsg_subscribe("plus", plus);
	holymsg_subscribe("minus", minus);
    holymsg_run();
    return 0;
}

