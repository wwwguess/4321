#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"�����"NOR);
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·ͨ�򱱷���
�����ǳ������������ǲ�ׯ��ר�ž���������Ρ�������һ����Ӫ��
�ſ�һ��ʯʨ��ŭĿ����
LONG
	);

	set("exits", ([
 "north" :__DIR__"bdj2",  
 "south" :__DIR__"tamgch",
 "west"  :__DIR__"ljbzh",
 "east"  :__DIR__"jwby",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

