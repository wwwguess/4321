// Room: /d/choyin/stonehole.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ�Һ������,˫Ŀ������.���˫�ֺ��󴥵���ʲô����(object),�������.
LONG
	);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
