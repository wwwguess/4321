// Room: /d/jingcheng/tamgch.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[31m¹ã³¡[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇ¾©³ÇµÄÖĞĞÄ£¬ËÄÌõ´ó½Ö½»»ãÓÚ´Ë¡£Î¡¶ë¸ß´óµÄÖÓÂ¥ËÊÁ¢ÑÛÇ°
Ã¿µ±Çå³¿Óë°øÍí£¬´¾ÆÓµÄÖÓÉù±ã»áÓÉ´Ë´«ÏòËÄÃæ°Ë·½¡£ÕâÀï³µË®Âí
Â¡£¬ÍùÀ´ÈË³±²»¶Ï¡£ÕâÊÇÒ»¸öºÜ´óµÄ¹ã³¡£¬ÇàÊ¯µØÃæ£¬³£ÇàµÄËÉ°Ø£¬
ÓªÔì³öÁËÒ»ÖÖºÍĞ³£¬ÓÄÑÅµÄÆø·Õ¡£¹ã³¡ÉÏÏ¡Ï¡À­À­µØÓĞ¼¸¸öÈË£¬±±
Ãæ¾ÍÊÇ»Ê³ÇÁË¡£ÄÏÃæÊÇ¿í³¨µÄÄÏ´ó½Ö¡£¶«Î÷Á½ÃæÊÇ³¤°²½Ö, ¶«±±ÊÇ
æäÕ¾£¬²»Ê±ÓĞ³µ³öÈë ¡£
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/libai" : 1,
	__DIR__"npc/girl" : 2,
]));
	set("outdoors", "city");

	set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"xchjie5",
	"north" : __DIR__"bdj1",
	"south" : __DIR__"ndj1",
	"east" : __DIR__"dchjie1",
]));

	setup();
	replace_program(ROOM);
}
