#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"��ȸ���"NOR);
	set("long", @LONG
��������ȸ��ֵ��жΡ������ǹ��Ӽ࣬������������������������
��ȸ��ֺ��ϴ�ֵ�ʮ��·�ڣ��������Ǿ��ǵķ������ڡ�
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"ndj3",
 "east" :__DIR__"zhq6",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

