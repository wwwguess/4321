// Room: /d/jingcheng/roupu.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32mÈÙ¼ÇÈâµê[2;37;0m");
	set("long", @LONG
ÈâÆÌÖĞÁÁÌÃÌÃµÄ£¬´òÉ¨µÄÒ²±È½Ï¸É¾«¡£ÈâÆÌµÄÀÏ°åÔ­ÊÇĞĞÎä³öÉí£¬
Ò²Ôø¸úËæ½«¾üÈ¥Î÷Óò´ò¹ıÕÌ¡£ÍËÎéºó»Ø³¤°²¿ªÁË¸öĞ¡ÈâÆÌ¡£ÒòÈË
ÀÏÊµ£¬´Ó²»¶Ì½ïÈ±Á½£¬ÈâÆÌµÄÉúÒâÒ²ÊÇÒ»ÈÕºÃ¹ıÒ»ÈÕ¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baih4",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/rong" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
