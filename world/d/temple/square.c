// Room: /u/k/karrimor/temple/entrance.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "���Ĺ۹㳡");
	set("long", @LONG
����վ�����Ĺ�ǰ�Ĺ㳡ǰ, һƬ��ʯӢ���̳ɵĹ㳡��һ����
ΰ��ʯʨ��վ�����ŵ�����, ʨ�ӵ��������������������Ƶ�ʯ����
�㳡�����뻹��һ������¯, ��¯����ð�����������̡�
LONG
	);

     set("item_desc", ([
         "door": (:this_object(), ({"look_door", "north"}): ),
     ]) );

	set("exits", ([ /* sizeof() == 2 */
     "north" : __DIR__"temple1",
     "south" : __DIR__"entrance",
]));

     create_door("north", "����ľ��", "south");

     set("outdoors", "temple");

	setup();
//	replace_program(ROOM);
}
