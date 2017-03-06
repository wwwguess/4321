// Room: /d/jingcheng/djdp.c
// Made by: ysgl

#include <ansi.h>
inherit HOCKSHOP;

void create()
{
	set("short", "[1;37m¶­¼Çµ±ÆÌ[2;37;0m");
	set("long", @LONG
ÕâÊÇ³¤°²³ÇÀï×î´óµÄÒ»¼Òµ±ÆÌÁË¡£ËØÀ´ÒÔÂòÂô¹«Æ½×Å³Æ¡£ÃÅ¿Ú¹ÒÁËÒ»¿éÅÆ
×Ó£¬¶­ÀÏ°åÊÇ¸öºÜ¾«Ã÷µÄÉúÒâÈË£¬¼ûÄã×ßÁË½øÀ´£¬ºÜ¿ÍÆøµØºÍÄã
º®êÑ£¬µ«ÑÛ¾¦ÀïÈ´Ã»ÓĞÊ²Ã´Ğ¦Òâ£¬ºÜÉóÉ÷µØ´òÁ¿×ÅÄã¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ndj1",
]));
        set("objects", ([
        __DIR__"npc/dong.c" : 1,
]));                
//    set("dangpu_location","yangzhou");
	setup();
}
