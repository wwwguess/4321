// /clone/board/kedian_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("˳����ջ���԰�", ({ "board" }) );
	set("location", "/d/heimuya/kezhan");
	set("board_id", "kezhan_b");
	set("long", "ǧ�����أ�һͳ����\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

