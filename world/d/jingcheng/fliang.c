// Room: /d/jingcheng/fliang.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m·á¼ÇÁ¸µê[2;37;0m");
	set("long", @LONG
ÕâÊÇÒ»¼ÒÉúÒâĞËÂ¡µÄÁ¸µê¡£·áÀÏ°å×øÔÚ¹ñÌ¨ºóÃæĞ¦Èİ¿É¾ÏµØ½Ó´ı
×Å¿ÍÈË¡£»î¼ÆÃÇÔÚÒ»±ßÃ¦Ã¦ÂµÂµµØ¹¤×÷×Å¡£Èç¹ûÄãÉíÎŞ·ÖÎÄ£¬Äã
»¹¿ÉÒÔÔÚÕâÀïÏò·áÀÏ°å´òÒ»Ğ©Áã¹¤£¬ÒÔ×¬Ò»Ğ©Ç®¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhq9",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/feng" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
