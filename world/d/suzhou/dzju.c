// Room: /d/suzhou/dzju.c
//by dwolf 
//97.11.5

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",MAG"���Ӿ�"NOR);
	set("long", @LONG
�����ھֵ���˯���ĵط����������ʮ����С����������һ���մ��������е��š�
LONG
	);               
	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_light", 1);

	set("exits", ([
		"southwest"  :__DIR__"bjhyuan", 
		"north" : __DIR__"hfang",
	]));                                
	create_door("north", "������", "south", DOOR_CLOSED);

	setup();
}

