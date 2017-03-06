// Room: /d/jingcheng/treeflow.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37mÈı»¨ÌÃ×ÜÌÃ[2;37;0m");
	set("long", @LONG
Èı»¨ÌÃÊÇ½üÄê½­ºşÖĞĞËÆğµÄÒ»¸ö°ïÅÉ£¬¿¿ÌæÈË´ò¼Ü¼°°óÆ±ÎªÓªÉú
×¬Ç®¡£µ½´¦ÕÒÄ»µØÆ¦Á÷Ã¥£¬´òÔÒÉÕÇÀ£®µ«ÓÉÓÚÕÒ²»µÀ×ã¹»Ö¤¾İ£¬
¹Ù¼ÒÓÖÄÃÆäÎŞ¿ÉÄÎºÎ¡£ÎİÀïÎ§ÁËÒ»°ïÈË£¬ÒõÉøÉøµÄ¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xw1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liumang" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
