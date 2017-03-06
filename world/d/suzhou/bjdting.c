// Room: /d/suzhou/bjdting.c
// by dwolf
//97.11.4 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"�ھִ���"NOR);
	set("long", @LONG
�����ھִ�����������ͷ�������һЩ���������������̸���⡣�����м������ӣ�
�������ӣ������Ϸ���Щ�裬���ġ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"lwchang",
		"north" : __DIR__"bjhyuan",
	]));

	set("objects", ([
		__DIR__"npc/jiang" : 1,  
		__DIR__"npc/furen" : 2,
	]));

	setup();
	replace_program(ROOM);
}

