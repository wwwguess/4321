#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"������"NOR);
	set("long", @LONG
�������ǳ��������ģ����һ�Ҵ����ˡ��������������ƣ���
���������ڶ������������㻹Ը��������ŮҲ�ر�࣬�����˻�
�����գ�������ɽ�˺���
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"xchjie2", 
 
	]));
	setup();
}

