// /clone/board/shaolin_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(RED "����" NOR + YEL"�粨¼" NOR, ({ "board" }) );
	set("location", "/d/shaolin/guangchang1");
	set("board_id", "shaolin_b");
	set("long", "����һ�������ֵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
