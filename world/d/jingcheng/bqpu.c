// Room: /d/jingcheng/bqpu.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m±øÆ÷ÆÌ[2;37;0m");
	set("long", @LONG
¸ÕÒ»½øÃÅ¾Í¿´µ½±øÆ÷¼ÜÉÏ°Ú×Å¸÷ÖÖ±øÆ÷£¬´ÓÉÏ°Ù½üÖØµÄ´óµ¶µ½ÇáÈç
½æ×ÓµÄ·É»ÇÊ¯£¬ÊÇÓ¦ÓĞ¾¡ÓĞ¡£Å®ÀÏ°åÊÇÀÏÓ¢ĞÛÏôÕñÔ¶µÄĞ¡Å®¶ù£¬Ò²
ÊÇÕñÔ¶ïÚ¾Ö¶şÀÏ°å£¬½íàş²»ÈÃĞëÃ¼¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dchjie1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoxiao" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
