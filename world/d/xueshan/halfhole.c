//by dwolf                 

#include <ansi.h>
inherit ROOM;              

string* objects = ({
		"guo1", 
		"guo2",
});

void create()
{      
	int i = random(sizeof(objects));
        set("short", "山洞");
        set("long", @LONG
	    你来到一个山洞，你感到比刚才热多了，仿佛不在雪山上了。洞中有一
个果子，不知道吃了会怎样。
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"hill2.c",
		"north" : __DIR__"house.c",
                   ]));
        set("objects", ([
               __DIR__"npc/obj/"+objects[i] : 1]));
        setup();
}

