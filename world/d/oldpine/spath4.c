// Room: /d/oldpine/spath4.c

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
����һ����ֱ���µ��������ϵͣ���·���Գ������������������
�ּ���Լ�����������ߴ�����ˮ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"spath3",
//  "south" : "/d/choyin/n_gate",
]));
	set("no_clean_up", 0);
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}
