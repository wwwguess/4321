#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"�����"NOR);
	set("long", @LONG
������һ��������ʯ�����ϣ������Ǳ��Ŵ�ֺ������ֵ�ʮ
��·�ڡ�������һ�����ֺŵ�ҩ�̣�������ҩ����������һ�ҡ�
����ңң�ɼ��ʳǴ��š�
LONG
	);

	set("exits", ([
 "north" :__DIR__"bdj3",  
 "south" :__DIR__"bdj1",
 "west"  :__DIR__"ylby",
 "east"  :__DIR__"hchyp",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

