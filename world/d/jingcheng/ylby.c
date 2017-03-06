// Room: /d/jingcheng/ylby.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37mÓùÁÖ¾üÓª[2;37;0m");
	set("long", @LONG
ÓùÁÖ¾üÓªÀï¹ûÈ»±È±ğ´¦±øÓª¼ÍÂÉÉ­ÑÏ¡£Î÷±ßÒ»ÅÅÊ¿±øÕıÔÚ²ÙÁ·±øÆ÷£¬
±±ÃæµÄ±ø¶¡ÔÚ´ò×®Á·Á¦Æø¡£¿¿ÃÅ¿Ú´¦¼¸Ô±½«¾üÕıÔÚÀ´»ØÑ²ÊÓ¡£¿´ËûÃÇ
¶¥¿ø¹á¼×µØ×ßÀ´×ßÈ¥£¬ÕæÊÇÍş·çÁİÁİ¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"bdj2",
]));
	set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/fu-j" : 3+random(3),
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
