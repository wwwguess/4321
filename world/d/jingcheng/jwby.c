// Room: /d/jingcheng/jwby.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m½ûÎÀ¾üÓª[2;37;0m");
	set("long", @LONG
¾©³Ç×¤Ôú×ÅÊıÍò½ûÎÀ¾ü£¬±£ÎÀ»ÊÉÏµÄ°²È«£¬µ«´ó¶àÊı¶¼ÔÚ³ÇÍâ°²Óª¡£
ÕâÀï×¤ÔúµÄÊÇÇØÇíµÈÈË´Ó½ûÎÀ¾üÖĞÇ×ÊÖÌô³öÀ´µÄÓĞ²ÅÖ®Ê¿¡£Æ½ÈÕÀï¼¸
Ô±½«¾ü³£À´´«ÊÚ±ø·¨£¬Ï£ÍûÈÕºóËûÃÇÄÜÔÚÕ½³¡ÉÏÒ»ÏÔÉíÊÖ¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bdj1",
]));
/* set("objects", 
        __DIR__"npc/fu-j": 3+random(3),
]));
 */
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
