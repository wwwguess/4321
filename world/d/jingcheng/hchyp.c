// Room: /d/jingcheng/hchyp.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m»Ø´ºÒ©ÆÌ[2;37;0m");
	set("long", @LONG
ÕâÊÇ³¤°²³ÇÒ»¼ÒÀÏ×ÖºÅµÄÒ©ÆÌ£¬ÕâÒ©ÆÌ¼òÖ±Ì«ÀÏÁË£¬ÒÔÖÂÓÚØÒ¶îÉÏ
µÄ¡°»Ø¡±×Ö¶¼¿ì¿´²»³öÀ´ÁË¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bdj2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yang" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
