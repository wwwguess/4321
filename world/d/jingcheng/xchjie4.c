#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLU"��������"NOR);
	set("long", @LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�������ˡ����������Ŵ�
�ֺ�������ֵ�ʮ��·�ڡ��ϱ���һ����ۡ��һ����ʲô���ס��
�ط��������ǳ����ǵ��ܶ����ţ����ܹҽǣ��Եļ������ơ�
LONG
	);

	set("exits", ([
 "west" :__DIR__"xchjie3",
 "east" :__DIR__"xchjie5",
 "north":__DIR__"chanf",
 "south":__DIR__"zgf",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

