// Room: /d/jingcheng/gzj.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m¹ú×Ó¼à[2;37;0m");
	set("long", @LONG
¹ú×Ó¼àÊÇ¹ú¼ÒÅàÑø¸ß¼¶ÈË²ÅµÄµØ·½¡£³¯Í¥µÄÑ§·çºÜÅ¨£¬ÔÚÕâÀï²»Ê±
¿ÉÒÔ¿´µ½ÈıÈıÁ½Á½µÄÑ§ÉúÄ£ÑùµÄÈË´óÉùÕù±ç×ÅÊ²Ã´ÎÊÌâ£¬»¹ÓĞÒ»Ğ©
ÀÏÏÈÉúÃÅõ¾×ÅÃ¼Í·´Ò´Ò×ß¹ı£¬ÏóÊÇÔÚË¼¿¼×ÅÊ²Ã´ÎÊÌâ¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ndj2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiucai" : 2,
        __DIR__"npc/jiaoshou" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
