// Room: /d/jingcheng/yfangup.c
// Made by: ysgl  
//added by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"�ַ���¥"NOR);
	set("long", @LONG
�ַ�¥���Եø������֣�������������������������������
���ӣ���ǩ����Ǯ�����̵����������������ӣ������Ƕĵ�
�����ء�
LONG
	); 
	set("objects", ([
		__DIR__"npc/eba.c" : 1,
		__DIR__"npc/liuyuer.c" : 1,
		__DIR__"npc/genu.c" : 2,
]));
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"cayfang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
