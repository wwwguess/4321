#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"�������"NOR);
	set("long", @LONG               
������������ֵ��жΡ�������һ��С�ţ�ͨ��Ҷ�ϲ��á�����
����һ��ӣ�ʱ�����˳��롣������������ֺ���������ֵ�ʮ��
·�ڡ�
LONG
	);

	set("exits", ([
 "north"  :__DIR__"ql2",
 "south"  :__DIR__"xchjie3",
 "west"   :__DIR__"yshct",
 "east"   :__DIR__"mzh4",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

