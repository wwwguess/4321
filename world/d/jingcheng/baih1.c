#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"�׻����"NOR);
	set("long", @LONG
  �׻���ֵ��ϲ��ǳ��������������ֳ������еĵط���·��
��һ��ͨ����Ъ��С�ƹݡ�
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"baih2",
 "south" :__DIR__"dchjie3",
 "east" :__DIR__"jiuguan1",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

