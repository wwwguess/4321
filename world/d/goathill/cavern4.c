// Room: /d/goathill/cavern4.c

inherit ROOM;

void create()
{
	set("short", "�Ҷ�");
	set("long", @LONG
������һ���������Ҷ��������߽�����Ҷ��ŷ���ԭ������·����
��������͸������΢�⣬����Ƕ�Ѩ�ĳ��ڣ�����һ̲̲����ɫ����
�ﲻ֪��ʿʲô��������������һ��ζ��Ҳû�С�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"cavern1",
	]));
	set("objects", ([
		__DIR__"npc/worm": 2,
		__DIR__"npc/big_worm": 1
	]) );

	setup();
	replace_program(ROOM);
}
