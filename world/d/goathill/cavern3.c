// Room: /d/goathill/cavern3.c

inherit ROOM;

void create()
{
	set("short", "��Ѩ");
	set("long", @LONG
����һƬ�����ᣬ�����ȫ���������ܲ�����ײ���ұڣ���������
�ߴ��������ˮ����������������һ��ȴ�������������Ǭ��Ӳ����ʯ
�����ϲ������������ֳ�Ĳ�֪��������ʹ��ÿһ�����ߵ��쳣����
��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"cavern2",
	]));
	set("objects", ([
		__DIR__"npc/big_worm": 2,
		__DIR__"npc/huge_worm": 2,
	]) );

	setup();
	replace_program(ROOM);
}
