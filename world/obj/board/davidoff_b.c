// davidoff_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name( HIC "���輯" NOR, ({ "board" }) );
	set("location", "/u/d/davidoff/workroom");
	set("board_id", "davidoff_b");
	set("long",	"һ����ɫ��Ƥ�����µ���ᡣ\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
