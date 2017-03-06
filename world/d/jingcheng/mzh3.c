// Room: /d/jingcheng/mzh3.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37mÃñÕ¬[2;37;0m");
	set("long", @LONG
Õâ»§ÈË¼ÒÔÚ³¤°²³ÇÀïÒ²Ëã±È½Ï¸»Ô£µÄÁË¡£ÄĞÖ÷ÈË³£Äê¾­ÉÌÔÚÍâ£¬ÆŞ
×ÓÔÚ¼ÒÖ÷³Ö¼ÒÎñ¡£ÈçÍ¬³¤°²³Ç´ó¶àÊıÈË¼ÒÒ»Ñù£¬ÎİÀï¹©×ÅÄÏº£¹ÛÒô
ºÍ¹ØÍõÒ¯µÄÉñÏñ¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baih3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yahuan" : 2,
        __DIR__"npc/oldwoman" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
