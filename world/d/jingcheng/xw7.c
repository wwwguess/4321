// Room: /d/jingcheng/xw7.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[30mĞşÎä´ó½Ö¶¡×ÖÂ·¿Ú[2;37;0m");
	set("long", @LONG
ÕâÀïÊÇĞşÎä´ó½ÖºÍ°×»¢´ó½ÖµÄ¶¡×ÖÂ·¿Ú¡£ÏòÄÏ×ßÒ»¶Î¿ÉÒÔ¿´µ½Ò»×ù
ÁúÍõÃí¡£¾©³ÇµÄÓéÀÖ³¡Ëù´ó¶à¾Û¼¯ÔÚ°×»¢´ó½ÖµÄÄÏ¶Ë¡£
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"baih3",
  "south" : __DIR__"baih2",
  "west" : __DIR__"xw6",
]));
	set("no_clean_up", 0);
	set("outdoors", "city");

	setup();
	replace_program(ROOM);
}
