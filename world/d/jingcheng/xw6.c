#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"������"NOR);
	set("long", @LONG
�����������ֵ��жΡ�������һ�����ӣ����������ĸ�����
��������ݡ��������һ��լԺ�ǵ���������լ�ڡ������߼���
���������ֺͰ׻���ֵ�ʮ��·�ڡ�
LONG
	);

	set("exits", ([
 "east"  :__DIR__"xw7",
 "west"  :__DIR__"xw5",
 "south" :__DIR__"jiangjun",
 "north" :__DIR__"jdwg",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

