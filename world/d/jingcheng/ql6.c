#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"�������"NOR);
	set("long", @LONG
������������ֵ��϶Σ���·Ҳ����ƽ��������������������˾�
�ò����ڶ����ˡ�������һ��Ƭ�Ŀյأ�����Щľ��שͷ�������
Ҫ�Ƿ��ӡ�
LONG         
	);

	set("exits", ([ 
 "north":__DIR__"zhq3",
 	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

