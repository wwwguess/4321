// Room: /d/choyin/yamen.c
# include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���и���һ��(borad),���µ��鰸�Ϸ��ű�,ī,ֽ,��,����ľ����.
���Ը�������.���°��Ÿ�ʽ�̾�,���δ����.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"yamen_iner",
                "south" : __DIR__"yamen_yard",
                      ]));
   create_door("south", "ͭ������", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
 set("objects", ([
                "/u/sbaa/rong" : 1,
		__DIR__"npc/judgeman" : 1,     
                __DIR__"npc/magistra" : 2,
                __DIR__"npc/yamen_po" : 2,     
                 ]) ); 	
        setup();
	replace_program(ROOM);
}
