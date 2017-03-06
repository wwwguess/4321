// Room: /d/jingcheng/chhuang.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m³ÇÚòÃí[2;37;0m");
	set("long", @LONG
³ÇÚòÃíÀïÏã»ğ¼«Ê¢¡£´ó¶àÊÇÀ´±£ÓÓ¼ÒÀïÆ½°²£¬ÉúÒâĞËÂ¡Ö®Àà¡£ÕıÖĞ
Ç°·½Ò»×ù°×°×ÅÖÅÖ£¬ÂúÁ³¸£ÏàµÄ³ÇÚò£¬×ó±ßÓĞÒ»Î»ÊÖ³ÖÕÊ²¾ºÍÃ«±Ê
µÄÅĞ¹Ù¡£Ò»Î»Ãí×£×ßÇ°×ßºó£¬ºÍ´ó¼Ò´ò×ÅÕĞºô¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"chhgch",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/miaozhu" : 1,
]));

	setup();
	replace_program(ROOM);
}
