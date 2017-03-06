// Room: /d/goathill/cavern1.c

inherit ROOM;

void create()
{
	set("short", "�Ҷ�");
	set("long", @LONG
����Ҷ����ڲ��ƺ�Զ��������ô��ұ�����һ��������ݷ�
�Ǳ�ʲô������������ģ�������ʲô���ȥ��ҧ����Ӳ�ֺ���ұ���
����Ѩ�ĳ������������͸��΢�⣬�����߸������߸���һ����Ѩ����
�����ƺ���ʲô���������������
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/worm" : 2,
]));
	set("exits", ([ /* sizeof() == 3 */
		"southeast" : __DIR__"cavern4",
		"northeast" : __DIR__"cavern2",
		"west" : __DIR__"canyon3",
]));

	setup();
	replace_program(ROOM);
}
