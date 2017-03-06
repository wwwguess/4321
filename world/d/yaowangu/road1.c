//by dwolf
//97.11.8

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"雪山小道"NOR);
	set("long",  @LONG
	  你走在静谧的雪山小道上，感到一种惬意的舒心。你忍不住哈哈大笑几声
。“哈哈哈哈－－－－”，结果引起轻微的雪崩，差点儿把你吓死。远处有一些蔓藤
挂在山道边。蔓藤后面是高大的山峰。
LONG
	);
	set("exits", ([
		"down" : __DIR__"foot.c",
		"northup" : __DIR__"road2.c",
]));
	setup();
}
