#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"���Ҿ��"NOR);
	set("long", @LONG
����Ķ������൱���������̫̫С������������·����������
����˵��˾͸����ˡ����к��һ���߳߶೤�Ĺ�̨����̨��ļ���
����һƥƥ�Ĳ��Ϻͳ��£�
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"zhq1",
	]));
      set("objects", ([
                __DIR__"npc/liuerniang" : 1,
  ]));
	setup();
	replace_program(ROOM);
}

