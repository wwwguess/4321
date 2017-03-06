// Room: /d/jingcheng/dchjie3.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32mÊ®×ÖÂ·¿Ú[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇ¶«ÃÅ´ó½ÖºÍ°×»¢´ó½ÖµÄÊ®×ÖÂ·¿Ú¡£Ò»Ö±Ïò¶«×ß¿ÉÒÔµ½¾©
³ÇµÄ¶«ÃÅ¡£Î÷±ßÒ»Ö±Í¨µ½³ÇÖĞĞÄ£¬Ô¶Ô¶ÍûÈ¥£¬ÖÓÂ¥ÒÀÎô¿É¼û£®
ÕâÀïÈËÀ´ÈËÍù£¬µ¹Ò²·±»ª¡£
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youxia" : 1,
]));
	set("outdoors", "city");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"baih1",
  "south" : __DIR__"baih4",
  "west" : __DIR__"dchjie2",
  "east" : __DIR__"dchjie4",
]));

	setup();
	replace_program(ROOM);
}
