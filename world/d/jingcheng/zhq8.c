#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"��ȸ���"NOR);
	set("long", @LONG
  ��������ȸ��ֵĶ��Ρ������߼�������ȸ��ֺͰ׻�
��ֵ�ʮ��·�ڡ�
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq7",
 "east" :__DIR__"zhq9",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

