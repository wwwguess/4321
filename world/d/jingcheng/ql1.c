#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"�������"NOR);
	set("long", @LONG               
������������ֵı��Σ�·����һ�������������ķ��ӣ���������
��뷽������¡������Ƴ���������������ֱʡ������������ֺ���
����ֵ�ʮ��·�ڡ�
LONG
	);

	set("exits", ([
 "south"  :__DIR__"xw3",
 "west"   :__DIR__"jjs",
 "east"   :__DIR__"mzh1",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

