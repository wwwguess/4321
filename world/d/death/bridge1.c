// Room: /d/death/bridge1.c

inherit ROOM;

void create()
{
	set("short", "�κ���");
	set("long", @LONG
������һ��������ʯ�ţ�����ʯ�����������֮�У���������ͷ��
��������ԼԼ��һ����¥��������ֲ�������ʵ��Ӱ���ǻþ�������
���涼��һ���޼ʵĴ���һ���������΢������д�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"bridge",
]));

	setup();
	replace_program(ROOM);
}
