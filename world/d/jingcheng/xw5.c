#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"������"NOR);
	set("long", @LONG
�����������ֵ��жΡ������������ֺͱ��Ŵ�ֵ�ʮ��·�ڡ�
�����ǳ����ǵ����̨�������������ʽ����������С����߿�ȥ
��һ���ߴ�ĸ��ڣ�һ����ʲô���ס�ĵط���
LONG
	);

	set("exits", ([
 "east"  :__DIR__"xw6",
 "west"  :__DIR__"bdj3",
 "north" :__DIR__"tianjt",
 "south" :__DIR__"tiejp",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

