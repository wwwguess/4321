// Room: /d/jingcheng/xjqzh.c
// Made by: ysgl

#include <ansi.h>
inherit BANK;

void create()
{
	set("short", "[1;37mÏà¼ÇÇ®×¯[2;37;0m");
	set("long", @LONG
ÕâÊÇÒ»¼ÒÀÏ×ÖºÅµÄÇ®×¯£¬ÏàÀÏ°åÊÇÉ½Î÷ÈË£¬Õâ¼ÒÇ®×¯´ÓËûµÄÒ¯Ò¯µÄ
Ò¯Ò¯µÄÒ¯Ò¯µÄÒ¯Ò¯ÄÇ±²¿ªÊ¼°ìÆğ£¬Ò»Ö±´«µ½ËûÊÖÀï£¬ÉùÓş·Ç³£ºÃ£¬
ÔÚÈ«¹ú¸÷µØ¶¼ÓĞ·Öµê¡£Ëü·¢ĞĞµÄÒøÆ±Í¨ĞĞÈ«¹ú¡£Ç®×¯µÄÃÅ¿Ú¹ÒÓĞÒ»
¿éÅÆ×Ó(paizi)¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xchjie5",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/banker" : 1,
]));
	set("item_desc", ([
	"paizi" : "±¾×¯¿É»»Ç®£¬´æÇ®£¬È¡Ç®£¬°üÄãÂúÒâ.\n
                   cun <ÊıÁ¿> <»õ±ÒÖÖÀà>\n
                   qu <ÊıÁ¿> (unit: coin)\n
                   check ²éÕË \n 
                   convert <ÊıÁ¿> <»õ±ÒÖÖÀà> to <»õ±ÒÖÖÀà>\n  ",
]));

	setup();
}
