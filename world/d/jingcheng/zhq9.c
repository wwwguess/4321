#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"��ȸ���"NOR);
	set("long", @LONG
  ��������ȸ��ֶ��εľ�ͷ�ˣ������Ǹ߸ߵĳ�ǽ������
��һ�����꣬�����������¡�����ӡ�
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq8", 
 "north" :__DIR__"fliang",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

