// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ʦ���԰�", ({ "board" }) );
	set("location", "/d/wiz/hall1");
	set("board_id", "wizard_b");
	set("long",
		"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
