#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", RED"��ȸ���"NOR);
	set("long", @LONG
���ﻹ����ȸ��ֵ��жΡ������߼����͵��׻�����ˡ�·����һ
�ҵ��������Сľ���̣����徲����û�м������߶���
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq5",
 "east" :__DIR__"zhq7",
 "south" :__DIR__"kmu",

	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

