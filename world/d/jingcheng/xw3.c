#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"ʮ��·��"NOR);
	set("long", @LONG
�����������ֺ�������ֵĽ���·�ڡ�����ԼԼ�ؿ�����������
������һ����õ��������Ӵ��Ա��仹�ڳ��ڣ��������ƣ�ȴ
�Ǹ�Σ�յ�ȥ�����������Ӻ���������ҵ�˿ڴ����ڴ˵ء�
LONG
	);

	set("exits", ([
 "west"  :__DIR__"xw4",
 "east"  :__DIR__"xw2", 
 "north" :__DIR__"ql1",
 "south" :__DIR__"ql2",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

