
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ����ʯ���̳ɵ�ɽ����������ï�ܵ���ľ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road4",
  "southdown" : __DIR__"road2",
]));
	set("outdoors", "taoguan");
	setup();
	replace_program(ROOM);
}
