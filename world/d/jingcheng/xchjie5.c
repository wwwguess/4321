#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLU"��������"NOR);
	set("long", @LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ����Կ�����¥
������ǰ�����澲������һ����֣���������Щ�����ˡ�������һ��
Ǯׯ�����쿴�����˽����������Ե��������¡��
LONG
	);

	set("exits", ([
 "west" :__DIR__"xchjie4",
 "east" :__DIR__"tamgch", 
 "north":__DIR__"slshj",
 "south":__DIR__"xjqzh",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

