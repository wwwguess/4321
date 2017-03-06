// Room: /d/jingcheng/nchkzh.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37mÄÏ³Ç¿ÍÕ»[2;37;0m");
	set("long", @LONG
Õâ¼Ò¿ÍÕ»½ô¿¿¾©³ÇÖĞĞÄ£¬ËùÒÔÉúÒâ·Ç³£ĞËÂ¡¡£¼æÖ®¼ÛÇ®µÍÁ®£¬¸ü
ÊÇ³ÉÁËÍâµØÓÎ¿ÍÂä½ÅµÄÊ×Ñ¡¡£Â¶Ìì°ÚÁËÆß°ËÕÅ×À×Ó£¬Èı½Ì¾ÅÁ÷ÈËµÈ
ÔÚ´Ë½ø½ø³ö³ö£¬ÂçÒï²»¾ø£¬¼¸¸öÅÜÌÃµÄĞ¡¶şÀ´À´»Ø»ØÕĞ´ı×ÅËÄ·½À´
¿Í¡£¶şÂ¥ÉÏÊÇÑÅÌü£¬ºóÃæÊÇ¿Í·¿¡£
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"nchkzh2",
  "west" : __DIR__"ndj1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer1" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
