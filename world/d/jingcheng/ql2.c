#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"�������"NOR);
	set("long", @LONG               
������������ֵ��жΣ������߼�������������ֺ�����
��ֵ�ʮ��·�ڡ������ǳ���ͷһ�������İ����̣�����
�����������ϡ�
LONG
	);

	set("exits", ([
 "north"  :__DIR__"xw3",
 "south"  :__DIR__"ql3",
 "west"   :__DIR__"jjbz",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

