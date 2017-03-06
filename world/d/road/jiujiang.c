// Room: /d/maintown/mt_gate1.c

#include <room.h>

inherit ROOM;


void create()
{
	set("short", "九江");
	set("long", @LONG
这儿就是交通发达的九江。往东可到鱼米之乡金陵、苏杭。
往西则到华中重镇武昌。南到景德镇。这里的来往商人很多。

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

        create_door("west", "长沙城大门", "east", DOOR_CLOSED);
       */ 
	setup();
        replace_program(ROOM);
}

