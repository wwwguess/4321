// /clone/board/shaolin_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(RED "武当" NOR + YEL"剑侠录" NOR, ({ "board" }) );
	set("location", "/d/wudang/sanqingdian");
	set("board_id", "wudang_b");
	set("long", "这是一个供武当弟子交流的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
