#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIM"�ϴ��"NOR);
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·ͨ���Ϸ���
�����ǳ�������һ���õ꣬�������ɡ�������һ�ҵ��̣�����
������������ϲ���ǡ�
LONG
	);

	set("exits", ([
 "north" :__DIR__"tamgch",
 "west"  :__DIR__"djdp",
 "south" :__DIR__"ndj2",
 "east"  :__DIR__"nchkzh",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

