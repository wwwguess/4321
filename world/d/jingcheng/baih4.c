#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"�׻����"NOR);
	set("long", @LONG
  �����ǰ׻���ֵ��жΡ������߼����ǰ׻���ֺͶ���
���ֵ�ʮ��·�ڡ�������һ�����̡�
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"baih5",
 "north" :__DIR__"dchjie3",
 "east" :__DIR__"roupu",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

