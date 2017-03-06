// Room: /d/jingcheng/jiangjun.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m½«¾ü¸®[2;37;0m");
	set("long", @LONG
    ÕâÀïÊÇµ±³¯´ó½«µÄ¹ÙÛ¡£¬Ä½ÃûÀ´²Î°ÝµÄÈËÒ²ºÜ¶à¡£´óÃÅÁ½²àÓÐ
Á½Í·¸ß´óµÄÊ¯Ê¨×Ó¡£¶«±ßÊÇÒ»¿Ã»±Ê÷£¬ÓôÓô´Ð´Ð£¬ÕÚ¸ÇÁË´ó°ë¸öÔº
×Ó£¬Õû¸öÔº×ÓÀïÒõÒõÁ¹Á¹µÄ¡£ÄÏ±ßÊÇ¸ö¿Õ³¡£¬´ó¸ÅÊÇ½«¾üÑÝÎäÖ®µØ¡£
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jjun2",
  "north" : __DIR__"xw6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinyu" : 1,
]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;

	inv = all_inventory(me);
	if( dir == "south" ){
		if( me->query("family/family_name") == "½«¾ü¸®"
		|| (int)me->query_temp("baishi") == 1
		|| !present( "qin yu", this_object() ) )
		return ::valid_leave(me, dir);
		for( i =sizeof(inv)-1 ; i >=0 ; i -- ){ 
			if( inv[i]->query("id") == "lingpai" ) 
				return ::valid_leave(me, dir);
		}
	return notify_fail(GRN"ÇØÓñÒ»ÏÂ×ÓÉì³öÒ»ÊÖ£¬À¹×¡ÄãËµ£º²»Öª"+
	RANK_D->query_respect(me)+"µ½½«¾ü¸®À´ÓÐºÎ¹ó¸É°¡£¿(answer)\n"NOR);
	}
	return ::valid_leave(me, dir);
}
