// Room: /d/village/road7.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
С·����������һ�Ŵ������������ݺ��ϵ���������͸����֦Ʈɢ��
������Ķ�����һ��Ƭ�����͵Ĺϵأ�һ���󹵺���С·�͹ϵ�֮�䣬��
�����ߵ�������Ĺ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"melonguard",
  "south" : __DIR__"road8",
  "west" : __DIR__"lakeside",
  "northup" : __DIR__"road5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
