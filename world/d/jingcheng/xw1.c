#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"������"NOR);
	set("long", @LONG
�����������ֵ��жΣ������߼������������ֺͱ��Ŵ�ֵ�ʮ
��·�ڡ�������һ���ڰ���ÿڣ����������Ķ���Щ���������
Ѫ�ȳ����ż����ʡ�
LONG
	);

	set("exits", ([
 "west"  :__DIR__"xw2",
 "east"  :__DIR__"bdj3",
 "north" :__DIR__"treeflow",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

