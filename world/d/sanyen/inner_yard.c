// Room: /d/sanyen/inner_yard.c

inherit ROOM;

void create()
{
	set("short", "ͥ԰");
	set("long", @LONG
����վ��ɽ���µ�ͥ԰��, ��ͥ԰�ﲻ������ïʢ, ����С����
ˮ, ��ɽ��ͤ, Ӧ�о���, ���ɷǷ��������м��ŷ�, ���ߴ�������
���Ǵ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"heal_room",
		"east" : __DIR__"temple",
	]));
	set("outdoors", "sanyen");

	set("objects", ([
		__DIR__"npc/cripple" :1
	]) );
	setup();
	replace_program(ROOM);
}
