#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"�������"NOR);
	set("long", @LONG               
������������ֵ��жΡ������߼�����������ֺ���ȸ��ֵ�ʮ��
·�ڡ���һƬס�Ķ��ǳ�͢��Ա��������Ǯ�˼ң���լ��Ժ������
���������ʮ�ֵĸɾ���������һ��С���̡�
LONG
	);

	set("exits", ([
 "south"  :__DIR__"zhq3",
 "north"  :__DIR__"ql4", 
 "east"   :__DIR__"jxzhp",
 "west"   :__DIR__"ytgj",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

