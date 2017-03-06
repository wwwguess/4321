// Room: /d/jingcheng/cayfang.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m³¤°²ÀÖ·»[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇ³¤°²³ÇÒ»¼ÒÓĞÃûµÄÓéÀÖ³¡Ëù¡£µ±Ò¹Ä»½µÁÙºó£¬ÕâÀï¾Í
¸ñÍâÈÈÄÖ¡£½ø½ø³ö³öµÄ¿ÍÈËÓĞ´ï¹Ù¹óÈË£¬ÄÏÀ´±±ÍùµÄÉÌÂÃ£¬
ÀË¼£ÌìÑÄµÄÓÎ×Ó£¬ÈıÎå³ÉÈºµÄ±øÊ¿£¬ÓĞÊ±Ò²ÄÜ¿´¼ûÒ»Ğ©×÷Ë×
¿Í´ò°çµÄÉ®ÈË»òµÀÊ¿¡£
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"yfangup",
  "west" : __DIR__"baih6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youke" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
