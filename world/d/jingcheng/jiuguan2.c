//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"С�ػ��ƼҶ�¥"NOR);
	set("long", @LONG
����һ�ҳ�������������ľƹݡ����ﲻ����Ӧ���صĸ���
���ƣ���Ҳ�������������������ĸ������ơ���ף���
֪�¶�������ĳ��͡�����ֻ��һ�����ˡ�
LONG         
	);   
	set("objects", ([
		"/d/jingcheng/npc/qinge.c" : 1,
]));

	set("exits", ([ 
  "down" : __DIR__"jiuguan.c", 
 
	]));
	setup();
	replace_program(ROOM);
}

