#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", YEL"�ʻ���"NOR);
	set("long", @LONG
     �������������ǵĻ��꣬���ϰ��Ǿ��ǳ����������ˣ����������Ӣ���ˬ
�������� ����������æ���к������������Ŀ��ˡ��������������ͷף����涷��
�Ļ��ܡ�
LONG         
	);
        set("objects", ([
		__DIR__"npc/fsgirl.c" : 1,
]));
	set("exits", ([ 
 "east" :__DIR__"baih5",  
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

