// Room: /d/choyin/yamen_yard.c
# include <room.h>
inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
Ժ�ڲ�ľ��ï,ͤ鿴�������,�ɼ���λ��̫үҲ��λ����.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"court1",
  "north" : __DIR__"yamen",
]));
   create_door("north", "ͭ������", "south", DOOR_CLOSED);   	
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/magistra" : 4     
                         ]) ); 
	setup();
      replace_program(ROOM);
}
