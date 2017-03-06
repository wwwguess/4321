// Room: /d/goathill/cavern2.c

inherit ROOM;

void create()
{
	set("short", "�Ҷ�");
	set("long", @LONG
����������һ����������Ҷ�������ǰ�������ϱ�������Щ������
����Ƕ�Ѩ�ĳ��ڣ������ƺ���Щ��ˮ����������������߹�ȥ������
����ϸ����о��ű���һЩ����������������ٽ�����Щ��ģ�һ��
���ĵĸо�ѹ�������θ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"cavern3",
		"southwest" : __DIR__"cavern1",
	]));
	set("objects", ([
		__DIR__"npc/fat_worm" : 1,
		__DIR__"npc/worm" : 3,
	]) );

	setup();
	replace_program(ROOM);
}
