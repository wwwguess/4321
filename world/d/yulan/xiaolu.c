
inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ����ͨ��ɽ��С·����������������ȥ�������ɼ������ȹȿڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/yulan/secrect2",
  "east" : "/d/yulan/gukou",
]));
	setup();
	replace_program(ROOM);
}
