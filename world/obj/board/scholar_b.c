// scholar_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����", ({ "book" }) );
	set("location", CLASS_D("scholar") + "/entrance");
	set("board_id", "scholar_b");
	set("long",	"һ�������ɵ���򣬹��������������Լ��¡�\n" );
	setup();
	set("capacity", 40);
	replace_program(BULLETIN_BOARD);
}
