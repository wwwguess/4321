// Room: /d/suzhou/dangpu.c
// by dwolf
//97.11.4 

#include <ansi.h>
inherit HOCKSHOP;

void create()
{
	set("short", MAG"当铺"NOR);
	set("long", @LONG
	这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台
上摆着一个牌子(paizi)，柜台后坐着老板阿锈，一双漂亮的大眼睛上上下下打量着
你。一个垂暮阿绣美色的恶霸正在这儿。
LONG
	);
	set("no_beg",1);
	set("no_steal", 1);

	set("item_desc", ([
		"paizi" : @TEXT
		公平交易    
	目前本店提供如下服务：
    pawn(典当/查看已典当物品)
    redeem(赎回典当物品)
    value(给物品估价)。
TEXT
	]));
	set("objects", ([
                __DIR__"npc/axiu" : 1, 
		__DIR__"npc/eba" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"eroad1",
	]));

        set("dangpu_location","suzhou");
	setup();
}

