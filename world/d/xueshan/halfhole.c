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
        set("short", "ɽ��");
        set("long", @LONG
	    ������һ��ɽ������е��ȸղ��ȶ��ˣ��·���ѩɽ���ˡ�������һ
�����ӣ���֪�����˻�������
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

