#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"ʮ��·��"NOR);
	set("long", @LONG
�����ǰ׻���ֺ���ȸ��ֵ�ʮ��·�ڡ��⸽���ĵط��ǳ�����
����������ĥ��֮����
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq6",
 "east" :__DIR__"zhq8", 
 "north" :__DIR__"baih5",
 "south" :__DIR__"baih6",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

