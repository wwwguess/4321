// Room: /d/jingcheng/baih3.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m°×»¢´ó½Ö[2;37;0m");
	set("long", @LONG
  ÕâÀïÊÇÇàÁú´ó½ÖµÄ±±¶Î£¬Î÷±ßÊÇÒ»¼ÒÎä¹İ£¬¸ô×ÅÇ½Ò²ÄÜÌıµ½ÀïÃæºß
¹şµÄÁ·È­¡£ÄÏ·½ÊÇÇàÁú´ó½ÖºÍĞşÎä´ó½ÖµÄÊ®×ÖÂ·¿Ú¡£
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinshi" : 1,
]));
	set("outdoors", "city");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xw7",
  "east" : __DIR__"mzh3",
]));

	setup();
}
