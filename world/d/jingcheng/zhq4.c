#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"��ȸ���"NOR);
	set("long", @LONG
��������ȸ��ֵ����Ρ������߼�������ȸ��ֺ�������ֵ�ʮ
��·�ڡ���Χ�������������ˡ�ż���м���Ժ�䣬ȴҲ�ǲ��ڵ�
�ڣ����ò�������˵��������Ҫ����λ�����Ǹ��ڣ����ϰ��ն�
�����ˡ�
LONG         
	);

	set("exits", ([ 
 "east" :__DIR__"zhq3",  
 "south" :__DIR__"mzh10",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

