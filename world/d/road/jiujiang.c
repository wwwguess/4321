// Room: /d/maintown/mt_gate1.c

#include <room.h>

inherit ROOM;


void create()
{
	set("short", "�Ž�");
	set("long", @LONG
������ǽ�ͨ����ľŽ��������ɵ�����֮����ꡢ�պ���
�����򵽻�������������ϵ�������������������˺ܶࡣ

LONG           
);


	set("exits", ([ /* sizeof() == 2 */
		  "south":"/d/road/rjjtocs0",
//		  "north" : "/d/road/ryytocs2",	
		  "west" : "/d/road/rjjtowc0",
		  "east" : "/d/road/rcstoyt0",]));
/*

	set("objects", ([
		"/d/maintown/npc/gateman" : 2 ]) );  

        set("no_clean_up", 0);
        set("outdoors", "maintown");

        create_door("west", "��ɳ�Ǵ���", "east", DOOR_CLOSED);
       */ 
	setup();
        replace_program(ROOM);
}

