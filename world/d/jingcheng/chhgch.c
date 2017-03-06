// Room: /d/jingcheng/chhgch.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m³ÇÚò¹ã³¡[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇ³ÇÚòÃíÇ°µÄÒ»Æ¬¹ã³¡£¬»ÆÍÁ´òÑ¹µÄµØÃæÊ®·ÖÆ½Õû£¬ÖÜÎ§ÓĞÒ»
Ğ©Ê¯°åÆÌµÄµÀÂ·£®ÈËÒ²ÌØ±ğµÄ¶à£¬ÓĞ¼·×Å¿´ÂôÒÕµÄ£¬ÓĞÂò¶«Î÷³ÔµÄ£¬
»¹ÓĞÒ»ÈºĞ¡º¢Î§×ÅÂôÌÇÈËµÄ¿´Ï¡º±¡£
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"north" : __DIR__"chhuang",
 		"south" : __DIR__"xw4",
  		"east" : __DIR__"gdd",
		]));
	
	set("objects", ([ /* sizeof() == 1 */
        	__DIR__"npc/tseller.c" : 1,
		__DIR__"npc/kid" : 2,
        	__DIR__"npc/kid2" : 1,
		]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
