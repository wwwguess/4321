// Room: /d/suzhou/biaoju.c
// by dwolf
//97.11.4 
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"威远镖局"NOR);
	set("long", @LONG
	你来到一座结构宏伟的建筑前，左右石坛上各插着一根两丈多高的旗杆，杆
上青旗飘扬。右首旗子用金线绣着一头张牙舞爪的飞龙，龙四周祥云缭绕。左首旗子
上写着“威远镖局”四个金黄大字，银钩铁划，刚劲非凡。入口处排着两条长凳，几
名趟子手坐着把守。
LONG
	);

	set("exits", ([
		"south" : __DIR__"wroad3",
		"north" : __DIR__"lwchang",
		"west" : __DIR__"qxku",
	]));

	set("objects", ([
		__DIR__"npc/fighter" : 2,
	]));

	setup();
	replace_program(ROOM);
}

