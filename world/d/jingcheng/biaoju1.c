// Room: /d/jingcheng/biaoju1.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32mÕñÔ¶ïÚ¾Ö[2;37;0m");
	set("long", @LONG
ÕñÔ¶ïÚ¾ÖµÄ´´Ê¼ÈËÊÇÀÏÓ¢ĞÛÏôÕñÔ¶¡£ÏôÀÏÓ¢ĞÛÄêÊÂÒÑ¸ß£¬ÔçÒÑ²»¹ı
ÎÊ½­ºşÊÇ·ÇÁË¡£ÏÖÔÚïÚ¾ÖµÄ¶ÔÍâÊÂÎñ¶¼ÓÉÏôÕñÔ¶µÄ´Î×ÓÏôÉıÖ÷Àí¡£
¶øÄÚ²¿ÊÂÎñÔòÓĞĞ¡Å®ÏôÏô¾ö¶¨¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dchjie2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiao-sh" : 1,
        __DIR__"npc/biaotou" : 2,
        __DIR__"npc/tz-shou" : 3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
