//ROOM:/d/suzhou/kezhan.c
//by dwolf
//97.11.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG "客店" NOR);
	set("long", @LONG
	这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚，你可
以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待着南腔北调的客
人。客店的主人从不露面，他究竟是谁，有各种各样的猜测。墙上挂着一个牌子(paizi)
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
        "paizi" : "后院客房，每夜五两白银。\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"sroad1",
		"east" : __DIR__"kezhan2",
	]));

	setup();
	"/obj/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{
         object *inv;
    	 int i;

    	 if ( me->query_temp("riden") && dir == "east")
		return notify_fail("这个地方不能骑马过去。\n");
         if ( !userp(me) && dir == "east" )
			return 0;      

	if ( !me->query_temp("rent_paid") && dir == "east" )
	return notify_fail("店小二一下挡在门前，白眼一翻：怎麽着，想白住啊！\n");

/*	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("店小二跑到你前边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");*/

	return ::valid_leave(me, dir);    
}
       
