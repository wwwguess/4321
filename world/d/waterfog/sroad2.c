// Room: /d/waterfog/sroad2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʵ����ʯ����������������ɽ�������������ϱ�
��������Զ������ͨ��ˮ�̸��ʯ�ס�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/waterfog/sroad1",
  "west" : "/d/waterfog/sroad3",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
