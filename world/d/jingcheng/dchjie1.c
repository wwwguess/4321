#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"��������"NOR);
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·ͨ�򶫷���
��������վ�������Ÿ������ż���ʱ��ʱ�з��������ϱߵ�����
����Զ�ھֿ��ģ�ר��һЩ������������ǳ��е�����㳡��
LONG
	);

	set("exits", ([
 "west" :__DIR__"tamgch",
 "east" :__DIR__"dchjie2",
 "south" :__DIR__"bqpu",
 "north" :__DIR__"postoffice",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

