// Room: /d/jingcheng/dchjie4.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m¶«³¤°²½Ö[2;37;0m");
	set("long", @LONG
Ò»Ìõ¿íÀ«µÄÇàÊ¯°åÂ·¡£Â·±±ÊÇÒ»×ù±øÓª£¬¿ÉÒÔÌıµ½±øÊ¿ÃÇ²ÙÁ·µÄÉùÒô¡£
Î÷ÃæÒÑ¾­¿ÉÒÔ¿´µ½ÖÓÂ¥¡£ÍùÀ´ĞĞÈË²»¶Ï£¬³Ç¶«µÄ²ËÅ©Ò»°ã¶¼ÔÚÌìÃÉÃÉ
ÁÁÊ±½«Êß²ËÔËÍù³ÇÖĞ£¬ÓÖ³ÃÏ¦ÑôÂäÉ½Ç°¸Ï»Ø¼ÒÖĞ¡£
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/youxia" : 1,
]));
	set("outdoors", "city");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"bingying",
  "west" : __DIR__"dchjie3",
  "east" : __DIR__"dchjie5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
