#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"�����ʮ��·��"NOR);
	set("long", @LONG
�����Ǳ��Ŵ�ֺ������ֵ�ʮ��·�ڡ��򱱿�����Լ�����ʹ���
��ǽ��
LONG
	);

	set("exits", ([
 "north" :__DIR__"wumen",  
 "south" :__DIR__"bdj2",
 "west"  :__DIR__"xw1",
 "east"  :__DIR__"xw5",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

