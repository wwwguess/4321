// Room: /d/waterfog/wpath4.c

inherit ROOM;

void create()
{
	set("short", "��ʯ����");
	set("long", @LONG
������������һ������ɽ�ڶ����İ�ʯ�����ϣ���������Խ��Խ��
���������Ѿ�������������ɽ���������ں�̨����ġ���������������
������ת�������¶Ƚϻ���ɽ������Ķ�����һ������׵���ȣ���
����ȿ����������治Զ����ˮ�̸�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/waterfog/wpath3",
  "northwest" : "/d/waterfog/wpath5",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
