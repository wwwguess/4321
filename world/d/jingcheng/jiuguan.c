#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"С�ػ��Ƽ�"NOR);
	set("long", @LONG
����һ�ҳ�������������ľƹݡ����ﲻ����Ӧ���صĸ���
���ƣ���Ҳ�������������������ĸ������ơ���ף���
֪�¶�������ĳ��͡�
LONG         
	);   
	set("objects", ([
		"/d/jingcheng/npc/waiter.c" : 1,
]));
        // This enables players to save this room as their startroom.
        set("valid_startroom", 1);

	set("exits", ([ 
 "west" :__DIR__"baih5",
 "up" : __DIR__"jiuguan2.c", 
 
	]));
	setup();
	replace_program(ROOM);
}

