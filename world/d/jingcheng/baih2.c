#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"�׻����"NOR);
	set("long", @LONG
  ������������ֵ��жΡ�·����һ����,�����ǽ������������߼���
�ǰ׻���ֺ������ֵĶ���·�ڡ�
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"xw7",
 "south" :__DIR__"baih1", 
 "east" :__DIR__"miao",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

