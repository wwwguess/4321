#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"������"NOR);
	set("long", @LONG
���ǳ����Ƕ����ǵ�һ��С���������������õġ��Ż�˵�úã�
����ʱ����š������Ե������˳��ʱ������һ��������������
�ġ���������ʱ���Ǻ���ġ�
LONG         
	);

      	set("objects", ([ 
        __DIR__"npc/farmer" : 1,
      ]));

	set("exits", ([ 
 "west" :__DIR__"baih2", 
 
	]));
	setup();
	replace_program(ROOM);
}

