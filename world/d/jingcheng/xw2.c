#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"������"NOR);
	set("long", @LONG
�����������ֵ��жΣ������������ֺ�������ֵ�ʮ��·�ڡ�
�����ٹ������־͵��˱���֡�
LONG
	);

	set("exits", ([
 "west"  :__DIR__"xw3",
 "east"  :__DIR__"xw1",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

