// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("һ����;���԰�", ({ "board" }) );
	set("location", "/u/cloud/tearoom");
	set("board_id", "common_b");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
