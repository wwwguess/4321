#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"�������"NOR);
	set("long", @LONG               
������������ֵ��жΡ�������һ��С��ͨ����ɽة��ĸ��ڡ�
��Ȼ���Ǵ����������ˣ�ֻ�ǽ���ʱ�ĳ��ڡ�������������ֺ�
�������ֵ�ʮ��·�ڡ�
LONG
	);

	set("exits", ([
 "south"  :__DIR__"ql5",
 "north"  :__DIR__"xchjie3",
 "west"   :__DIR__"westyf",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

